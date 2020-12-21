#include<bits/stdc++.h>
#include <queue>
using namespace std;

#define ElemType int
#define ERROR 0


class TreeNode
{
    friend class BinaryTree;
    public:
        TreeNode(): father(NULL), lson(NULL), rson(NULL), data(0), id(-1) {}
        TreeNode(TreeNode *f, TreeNode *l, TreeNode *r, ElemType e, int ID): 
                father(f), lson(l), rson(r), data(e), id(ID) {}
    private:
        TreeNode *father;
        TreeNode *lson, *rson;
        ElemType data;
        int id;
};

class BinaryTree
{
    public:
        BinaryTree()
        {
            this->size = 0;
            this->root = new TreeNode;
            this->root->father = NULL;
            this->root->lson = NULL;
            this->root->rson = NULL;
            this->root->data = 0;
            this->root->id = 0;
        }
        BinaryTree(ElemType elem)
        {
            this->size = 0;
            this->root = new TreeNode;
            this->root->father = NULL;
            this->root->lson = NULL;
            this->root->rson = NULL;
            this->root->data = elem;
            this->root->id = 0;
        }

        ~BinaryTree() {}

        void clear(TreeNode *node);
        bool insert(int parentID, char type, ElemType newElem);
        ElemType getData(int ID);
        int getParentID(int ID);
        /* 递归实现 遍历二叉树 */
        void preOrder(TreeNode *node);
        void inOrder(TreeNode *node);
        void postOrder(TreeNode *node);

    private:
        TreeNode *root;
        int size;

        TreeNode *search(int ID)
        {
            std::queue<TreeNode *> q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode *now = q.front();
                q.pop();
                if (now->id == ID)
                    return now;
                if (now->lson)
                    q.push(now->lson);
                if (now->rson)
                    q.push(now->rson);
            }
            return NULL;
        }
};

void BinaryTree::clear(TreeNode *node)
{
    if (node->lson)
        clear(node->lson);
    if (node->rson)
        clear(node->rson);
    delete node;
}

bool BinaryTree::insert(int parentID, char type, ElemType newElem)
{
    TreeNode *pos = search(parentID);
    if (!pos)
        return false;
    if ((type == 'L' && pos->lson) 
        || (type == 'R' && pos->rson))
        return false;
    TreeNode *node = new TreeNode(pos, NULL, NULL, newElem, ++this->size);
    if (type == 'L')
        pos->lson = node;
    if (type == 'R')
        pos->rson = node;
    return true;
}

ElemType BinaryTree::getData(int ID)
{
    /* 队列实现 搜索标记为ID的二叉树结点 */
    TreeNode *ptr = search(ID);
    if (!ptr)
        exit(ERROR);
    return ptr->data;
}

int BinaryTree::getParentID(int ID)
{
    TreeNode *ptr = search(ID);
    if (!ptr)
        return -1;
    return ptr->father ? -1 : ptr->father->id;
}

void BinaryTree::preOrder(TreeNode *node = NULL)
{
    if (!node)
        node = search(0);
    std::cout << node->id << " " << node->data << std::endl;
    if (node->lson)
        preOrder(node->lson);
    if (node->rson)
        preOrder(node->rson);
}

void BinaryTree::inOrder(TreeNode *node = NULL)
{
    if (!node)
        node = search(0);
    if (node->lson)
        inOrder(node->lson);
    std::cout << node->id << " " << node->data << std::endl;
    if (node->rson)
        inOrder(node->rson);
}

void BinaryTree::postOrder(TreeNode *node = NULL)
{
    if (!node)
        node = search(0);
    if (node->lson)
        postOrder(node->lson);
    if (node->rson)
        postOrder(node->rson);
    std::cout << node->id << " " << node->data << std::endl;
}

int main()
{
    cout<<"Succeeded!"<<endl;
    return 0;
}