#include "StackTemplate.h"

/* 将 10 进制非负整数 n 转换为 base 进制整数字符串 */
string BaseConverter(int n, int base)
{
    if (n == 0)
        return "0";
    string res = "";
    LinearStack<int> st;
    st.Clear();
    while (n)
    {
        st.Push(n % base);
        n /= base;
    }
    while (!st.Empty())
    {
        if (st.Top() < 10)
            res += (char)(st.Top() + '0');
        else 
            res += (char)(st.Top() - 10 + 'A');
        st.Pop();
    }
    return res;
}

/* 计算整型表达式，不含取余 */
int CalcExpression(string str)
{
    LinearStack<int> num;
    LinearStack<char> op;
    num.Clear(); op.Clear();
    int now = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            if (str[i] == '(')
            {
                op.Push('(');
                continue;
            }
            else if (!op.Empty())
            {
                if (op.Top() == '*')
                {
                    op.Pop();
                    int top = num.Top();
                    num.Pop();
                    now *= top;
                }
                else if (op.Top() == '/')
                {
                    op.Pop();
                    int top = num.Top();
                    num.Pop();
                    now = top / now;
                }
                if (str[i] == ')')
                {
                    num.Push(now);
                    while (op.Top() != '(')
                    {
                        int num1 = num.Top(); num.Pop();
                        int num2 = num.Top(); num.Pop();
                        if (op.Top() == '+')
                            num.Push(num1 + num2);
                        else 
                            num.Push(num2 - num1);
                        op.Pop();
                    }
                    op.Pop();
                    if (!op.Empty() && op.Top() == '*')
                    {
                        now = num.Top(); num.Pop();
                        op.Pop();
                        int top = num.Top();
                        num.Pop();
                        now *= top;
                        num.Push(now);
                    }
                    else if (!op.Empty() && op.Top() == '/')
                    {
                        now = num.Top(); num.Pop();
                        op.Pop();
                        int top = num.Top();
                        num.Pop();
                        now = top / now;
                        num.Push(now);
                    }
                    now = 0;
                    op.Push(str[++i]);
                    continue;
                }
            }
            num.Push(now);
            now = 0;
            op.Push(str[i]);
        }
        else 
            now = now * 10 + (str[i] - '0');
    }
    if (op.Top() == '*')
    {
        op.Pop();
        int top = num.Top();
        num.Pop();
        now *= top;
    }
    else if (op.Top() == '/')
    {
        op.Pop();
        int top = num.Top();
        num.Pop();
        now = top / now;
    }
    num.Push(now);
    while (!op.Empty())
    {
        int num1 = num.Top(); num.Pop();
        int num2 = num.Top(); num.Pop();
        if (op.Top() == '+')
            num.Push(num1 + num2);
        else 
            num.Push(num2 - num1);
        op.Pop();
    }
    return num.Top();
}

int main(void)
{
    std::cout << CalcExpression("1+2*3") << std::endl;
    std::cout << CalcExpression("(1+2)*3") << std::endl;
    std::cout << CalcExpression("(1+2)+2*3") << std::endl;
    std::cout << CalcExpression("1*(1+2*3+1)-2*3") << std::endl;
    std::cout << CalcExpression("50*(13+7*(4+2)/2)-6/2") << std::endl;
    int n;
    int base;
    std::cout << "Input n (Decimal n >= 0) and Base (base >= 2):\n";
    while (std::cin >> n >> base)
        std::cout << n << " (Decimal) in Base " << base << " is: " << BaseConverter(n, base) << std::endl;
    return 0;
}