#include<iostream>

using namespace std;

// class Student1 {
// public:
//     int a=0;
//     int b=0;

//     void fprint() {
//         cout << " a = " << a << " " << "b = " << b << "\n"<<endl;
//     }

//     Student1()
//     {
//         cout << "No-Parameter Constructor Student1" << endl;
//     }

//     Student1(int i):a(i),b(a)
//     { 
//         cout << "Parameter Constructor Student1" << endl;
//     } 

//     Student1(const Student1& t1)
//     {
//         cout << "Copy Constructor Student1" << endl;
//         this->a = t1.a;
//         this->b = t1.b;
//     }

//     Student1& operator = (const Student1& t1) // 重载赋值运算符
//     {
//         cout << "Assignment Function Student1" << endl;
//         this->a = t1.a;
//         this->b = t1.b;
//         return *this;
//     }

// };
// class Student2
// {
// public:

//     Student1 test;
//     Student2(Student1& t1) {
//         t1.fprint();
//         cout << "D: ";
//         test = t1;
//     }
//     //     Student2(Student1 &t1):test(t1){}
// };
// int main()
// {
//     cout << "A: ";
//     Student1 A;
//     A.fprint();

//     cout << "B: ";
//     Student1 B(2); 
//     B.fprint();

//     cout << "C: ";
//     Student1 C(B); 
//     C.fprint(); 

//     cout << "D: ";
//     Student2 D(C);
//     D.test.fprint();
// }

class CExample 
{
private:
 int a;

public:
 //构造函数
 CExample(int b)
 { 
  a = b;
  cout<<"creat: "<<a<<endl;
 }

 //拷贝构造
 CExample(const CExample& C)
 {
  a = C.a;
  cout<<"copy"<<endl;
 }
 
 //析构函数
 ~CExample()
 {
  cout<< "delete: "<<a<<endl;
 }

     void Show ()
 {
         cout<<a<<endl;
     }
};

//全局函数，传入的是对象
void g_Fun(CExample C)
{
 cout<<"test"<<endl;
}

int main()
{
 CExample test(1);
 cout<<endl;
 //传入对象
 g_Fun(test);
 cout<<endl;
 return 0;
}