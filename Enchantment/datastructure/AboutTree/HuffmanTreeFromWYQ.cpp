#include <iostream>
#include <Queue>
#include <vector>
#include "QueueTemplate.h"
#include "StackTemplate.h"
using std::cin;
using std::cout;

template<typename ElemType>
class TreeNode
{
    public:
        TreeNode(): father_(nullptr), leftson_(nullptr), rightson_(nullptr), data_(0), id_(-1) {}
        TreeNode(ElemType *e, int id, TreeNode *f, TreeNode *l = nullptr, TreeNode *r = nullptr): 
                father_(f), leftson_(l), rightson_(r), data_(e), id_(id) {}

        void SetFather(TreeNode *father){father_ = father;}
        void SetLeftSon(TreeNode *leftson){leftson_ = leftson;}
        void SetRightSon(TreeNode *rightson){rightson_ = rightson;}
        void SetData(ElemType *data){data_ = data;}
        void SetID(int id){id_ = id;}

        TreeNode *GetFather(){return father_;}
        TreeNode *GetLeftSon(){return leftson_;}
        TreeNode *GetRightSon(){return rightson_;}
        ElemType *GetData(){return data_;}
        int GetID(){return id_;}

        void Clear(TreeNode<ElemType> *node)
        {
            if (node->leftson_)
                Clear(node->leftson_);
            if (node->rightson_)
                Clear(node->rightson_);
            delete node;
        }

        int GetParentID(int id)
        {
            TreeNode<ElemType> *ptr = Search(id);
            if (!ptr)
                return -1;
            return ptr->father_ ? -1 : ptr->father_->id_;
        }

        void PreOrder(TreeNode<ElemType> *node = nullptr)
        {
            if (!node)
                node = Search(0);
            OutputNode(node);
            if (node->leftson_)
                PreOrder(node->leftson_);
            if (node->rightson_)
                PreOrder(node->rightson_);
        }

        void InOrder(TreeNode<ElemType> *node = nullptr)
        {
            if (!node)
                node = Search(0);
            if (node->leftson_)
                InOrder(node->leftson_);
            OutputNode(node);
            if (node->rightson_)
                InOrder(node->rightson_);
        }

        void PostOrder(TreeNode<ElemType> *node = nullptr)
        {
            if (!node)
                node = Search(0);
            if (node->leftson_)
                PostOrder(node->leftson_);
            if (node->rightson_)
                PostOrder(node->rightson_);
            OutputNode(node);
        }

        void LevelOrder(TreeNode<ElemType> *node = nullptr)
        {
            if (!node)
                node = Search(0);
            Queue<TreeNode<ElemType> *> q;
            q.Clear(); q.Push(node);
            while (!q.Empty())
            {
                TreeNode<ElemType> *now = q.Front(); q.Pop();
                OutputNode(now);
                if (now->leftson_)
                    q.Push(now->leftson_);
                if (now->rightson_)
                    q.Push(now->rightson_);
            }
        }

        void PreOrderStack(TreeNode<ElemType> *node = nullptr)
        {
            if (!node)
                node = Search(0);
            Stack<TreeNode<ElemType> *> st;
            st.Clear(); st.Push(node);
            while (!st.Empty())
            {
                TreeNode<ElemType> *now = st.Top(); st.Pop();
                OutputNode(now);
                if (now->rightson_)
                    st.Push(now->rightson_);
                if (now->leftson_)
                    st.Push(now->leftson_);
            }
        }

        void InOrderStack(TreeNode<ElemType> *node = nullptr)
        {
            if (!node)
                node = Search(0);
            Stack<TreeNode<ElemType> *> st;
            st.Clear();
            TreeNode<ElemType>* now = node;
            while (!st.Empty() || now)
            {
                while (now)
                {
                    st.Push(now);
                    now = now->leftson_;
                }
                now = st.Top(); st.Pop();
                OutputNode(now);
                now = now->rightson_;
            }
        }

        void PostOrderStack(TreeNode<ElemType> *node = nullptr)
        {
            if (!node)
                node = Search(0);
            Stack<TreeNode<ElemType> *> st;
            st.Clear();
            TreeNode<ElemType>* now = node;
            TreeNode<ElemType>* pre = NULL;
            while (!st.Empty() || now != nullptr)
            {
                while (now)
                {
                    st.Push(now);
                    now = now->leftson_;
                }
                now = st.Top();
                if (now->rightson_ == nullptr || now->rightson_ == pre)
                {
                    OutputNode(now);
                    pre = now; now = nullptr;
                    st.Pop();
                }
                else 
                    now = now->rightson_;
            }
        }

    protected:
        TreeNode<ElemType> *father_;
        TreeNode<ElemType> *leftson_, *rightson_;
        ElemType *data_;
        int id_;

        TreeNode<ElemType> *Search(int id)
        {
            Queue<TreeNode<ElemType> *> q;
            q.Clear(); q.Push(this);
            while (!q.Empty())
            {
                TreeNode<ElemType> *now = q.Front(); q.Pop();
                if (now->id_ == id)
                    return now;
                if (now->leftson_)
                    q.Push(now->leftson_);
                if (now->rightson_)
                    q.Push(now->rightson_);
            }
            return nullptr;
        }

        void OutputNode(TreeNode<ElemType> *node)
        {
            cout << node->id_ << " ";
        }
};

template <typename ElemType>
class HuffmanTreeNode: public TreeNode<ElemType>
{
    public:
        HuffmanTreeNode(): TreeNode<ElemType>(){}
        HuffmanTreeNode(int id)
        {
            this->SetFather(nullptr);
            this->SetLeftSon(nullptr);
            this->SetRightSon(nullptr);
            this->SetData(nullptr);
            this->SetWeight(0.0);
            this->SetID(id);
        }
        HuffmanTreeNode(ElemType *e, 
                        double p, 
                        int id, 
                        TreeNode<ElemType> *f = nullptr, 
                        TreeNode<ElemType> *l = nullptr, 
                        TreeNode<ElemType> *r = nullptr)
                        : TreeNode<ElemType>(e, id, f, l, r), weight_{p}{}

        void SetWeight(double weight){weight_ = weight;}

        double GetWeight() const{return weight_;}

        void Build(HuffmanTreeNode<ElemType> *a, HuffmanTreeNode<ElemType> *b)
        {
            a->SetFather(this);
            b->SetFather(this);
            this->SetFather(nullptr);
            this->SetLeftSon(a);
            this->SetRightSon(b);
            this->SetWeight(a->GetWeight() + b->GetWeight());
        }

        template <typename T>
        friend void GetHuffmanTree(const std::vector<HuffmanTreeNode<T>> &data,
                    HuffmanTreeNode<T> &root, int cnt);

        template <typename T>
        friend void GetHuffmanCode(const T &data, HuffmanTreeNode<T> *root);

        bool operator<(const HuffmanTreeNode<ElemType> &b) const{return this->GetWeight() > b.GetWeight();}

    protected:
        double weight_;
};

template <typename T>
void GetHuffmanTree(const std::vector<HuffmanTreeNode<T>> &data,
                    HuffmanTreeNode<T> &root, int cnt)
{
    std::priority_queue<HuffmanTreeNode<T>, std::vector<HuffmanTreeNode<T> > > pq;
    for (int i = 0; i < data.size(); ++i)
    {
        pq.push(data[i]);
    }
    while (!pq.empty())
    {
        HuffmanTreeNode<T> *node1, *node2;
        node1 = new HuffmanTreeNode<T>;
        node2 = new HuffmanTreeNode<T>;
        *node1 = pq.top(); pq.pop();
        if (pq.empty())
        {
            root.Build(node1, nullptr);
            break;
        }
        *node2 = pq.top(); pq.pop();
        if (pq.empty())
        {
            root.Build(node1, node2);
            break;
        }
        HuffmanTreeNode<T> *newnode;
        newnode = new HuffmanTreeNode<T>(cnt++);
        newnode->Build(node1, node2);
        pq.push(*newnode);
    }
}

template <typename T>
void GetHuffmanCode(HuffmanTreeNode<T> *root)
{

}

int main(void)
{
    HuffmanTreeNode<char> root(0);
    std::vector<HuffmanTreeNode<char> > data;
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; ++i)
    {
        int cid; char ch; double p;
        cin >> cid >> ch >> p;
        HuffmanTreeNode<char> tmp(&ch, p, cid);
        data.push_back(tmp);
    }
    GetHuffmanTree(data, root, cnt);
    root.PreOrder();
}

/*
2
1 A 1
2 B 2
*/

/*
9
1 A 15
2 B 6
3 C 7
4 D 12
5 E 25
6 F 4
7 G 6
8 H 1
9 I 15
*/