
#ifndef Init_Linear_Stack
#   define Init_Linear_Stack 1
/* 数据结构 */
#ifndef DataStructure_Practice
#   define DataStructure_Practice 1
#endif
/* 顺序存储 */
#ifndef DataStructure_Linear
#   define DataStructure_Linear 1
#endif
/* 面向对象 */
#ifndef DataStructure_Object
#   define DataStructure_Object 1
#endif

#include "INITIAL.h"

template <typename ElemType>
class LinearStack
{
    public:
        LinearStack() 
        {
            this->data_ = new ElemType[InitSize];
            this->top_ = -1;
            this->size_ = InitSize;
        }
        ~LinearStack() 
        {
            free(data_);
            this->data_ = NULL;
        }

        bool Empty()
        {
            if (this->top_ == -1)
                return true;
            return false;
        }

        void Clear() {this->top_ = -1;}

        ElemType Top()
        {
            if (Empty())
                exit(ERROR);
            return this->data_[this->top_];
        }

        void Push(ElemType newelem)
        {
            this->top_++;
            if (top_ >= InitSize)
                exit(OVERFLOW);
            this->data_[this->top_] = newelem;
        }

        void Pop()
        {
            if (Empty())
                exit(ERROR);
            --this->top_;
        }

    private:
        ElemType *data_;
        int top_;
        int size_;
};

#endif
