#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data,ltag,rtag;
    node *lchild,*rchild;
};

node *prevn=nullptr;  //global variable:pre node of current

void create_tree_pre(node **root)  /*构建先序树*/
{
    char data; cin >> data;

    if(data=='#')  //reverse
    {
        *root=nullptr;
    }
    else
    {
        *root=new node;  //setup new node location
        (*root)->data=data;  //access rootnode
        create_tree_pre(&((*root)->lchild));  //left child
        create_tree_pre(&((*root)->rchild));  //right child
    }
}

void threading(node **root)  /*先序遍历,全局变量途径*/
{
    if(*root)  //current node is not NULL
    {
        if(!(*root)->lchild)  //current do not have left child
        {(*root)->ltag=1,(*root)->lchild=prevn;}  //tag set 1,left child point to predecessor(parent)
        if(prevn!=nullptr && prevn->rchild==nullptr)  //current do not have right child
        {prevn->rtag=1,prevn->rchild=*root;}  //tag set 1,right child point to successor(child)
        prevn=*root;  //update predecessor

        if ((*root)->ltag == 0)  //left tag is 0,have left child,can traverse
        {threading(&((*root)->lchild));}  //traverse left tree
        if ((*root)->rtag == 0)  //right tag is 0,have right child,can traverse
        {threading(&((*root)->rchild));}  //traverse right tree
    }
}

void traverse(node *root)  /*preorder*/
{
    if(root==nullptr)
    {return;}

    cout << "current:" << (char)(root->data) << endl;
    if(root->ltag==1 || root->rtag==1)
    {
        (root->lchild!=nullptr) ? (void)(cout << "pre:" << (char)(root->lchild->data) << endl) : (void)0;
        (root->rchild!=nullptr) ? (void)(cout << "next:" << (char)(root->rchild->data) << endl) : (void)0;
    }
    
    if (root->ltag == 0)
    {
        traverse(root->lchild);
    }
    if (root->rtag == 0)
    {
        traverse(root->rchild);
    }
}

int main(void)
{
    node *root=nullptr;
    create_tree_pre(&root);
    threading(&root);
    traverse(root);

    return 0;
}

/*
    testset:A B D # # E # # C # F # #
*/