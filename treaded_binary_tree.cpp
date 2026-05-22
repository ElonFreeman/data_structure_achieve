#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data,ltag,rtag;
    node *lchild,*rchild;
};
node *prevn=nullptr;

void create_tree_pre(node **root)  /*构建先序树*/
{
    char data; cin >> data;

    if(data=='#')
    {
        *root=nullptr;
    }
    else
    {
        *root=new node;
        (*root)->data=data;
        create_tree_pre(&((*root)->lchild));
        create_tree_pre(&((*root)->rchild));
    }
}

/*void threading(node **root,node *prevnn)  //先序遍历
{
    if((*root)==nullptr)
    {return;}

    node *prevn=prevnn;
    if((*root)->lchild==nullptr)
    {(*root)->ltag=1,(*root)->lchild=prevn;}
    if((*root)->rchild==nullptr)
    {(*root)->rtag=1,(*root)->rchild=prevn;}
    prevn=*root;

    threading(&((*root)->lchild),prevn);
    threading(&((*root)->rchild),prevn);
}*/

void threading(node **root)  /*先序遍历,全局变量途径*/
{
    if(*root)
    {
        if(!(*root)->lchild)
        {(*root)->ltag=1,(*root)->lchild=prevn;}
        if(prevn!=nullptr && prevn->rchild==nullptr)
        {prevn->rtag=1,prevn->rchild=*root;}
        prevn=*root;

        if ((*root)->ltag == 0) threading(&((*root)->lchild));
        if ((*root)->rtag == 0)threading(&((*root)->rchild));
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