//normal tree
using namespace std;
#include<iostream>
#include<ctime>

struct treenode
{
    int data;
    treenode *firstchild;
    treenode *nextsibling;
};

//先序遍历:rootnode->left child->right child
void preordertraverse(treenode *rootnode)
{
    if(rootnode==nullptr)
    {
        return;
    }
    
    cout << rootnode->data << " ";
    treenode *child=rootnode->firstchild;

    while(child!=nullptr)
    {
        preordertraverse(child);
        child=child->nextsibling;
    }
}
//后序遍历
void postordertraverse(treenode *rootnode)
{

}
//中序遍历

//层次遍历


int main()
{
    void preordertraverse(treenode *);
    void postordertraverse(treenode *);

    //treenode *rootnode=nullptr;
    treenode *n1=new treenode{1,nullptr,nullptr},*n2=new treenode{2,nullptr,nullptr},*n3=new treenode{3,nullptr,nullptr},
             *n4=new treenode{4,nullptr,nullptr},*n5=new treenode{5,nullptr,nullptr},*n6=new treenode{6,nullptr,nullptr},
             *n7=new treenode{7,nullptr,nullptr},*n8=new treenode{8,nullptr,nullptr},*n9=new treenode{9,nullptr,nullptr},
             *n10=new treenode{10,nullptr,nullptr},*n11=new treenode{11,nullptr,nullptr},*n12=new treenode{12,nullptr,nullptr},
             *n13=new treenode{13,nullptr,nullptr},*n14=new treenode{14,nullptr,nullptr},*n15=new treenode{15,nullptr,nullptr},
             *n16=new treenode{16,nullptr,nullptr},*n17=new treenode{17,nullptr,nullptr},*n18=new treenode{18,nullptr,nullptr};

    //1
    //rootnode=n1;

    //2
    n1->firstchild=n2;
    n2->nextsibling=n3,n3->nextsibling=n4,n4->nextsibling=n5;

    //3
    n2->firstchild=n6;
    n6->nextsibling=n7,n7->nextsibling=n8;

    n3->firstchild=n9;
    n9->nextsibling=n10,n10->nextsibling=n11;

    n4->firstchild=n12;
    n12->nextsibling=n13;

    //4
    n6->firstchild=n14;
    n14->nextsibling=n15;

    n7->firstchild=n16;

    n8->firstchild=n17;

    n12->firstchild=n18;


    preordertraverse(n1);
    cout << endl << endl;

    postordertraverse(n1);
    cout << endl << endl;

    
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

struct treenode
{
    int data;
    treenode *firstchild,*nextsibling;

};

    treenode *root=nullptr;

    treenode *n1=new treenode{1,nullptr,nullptr},*n2=new treenode{2,nullptr,nullptr},*n3=new treenode{3,nullptr,nullptr},
             *n4=new treenode{4,nullptr,nullptr},*n5=new treenode{5,nullptr,nullptr},*n6=new treenode{6,nullptr,nullptr},
             *n7=new treenode{7,nullptr,nullptr},*n8=new treenode{8,nullptr,nullptr},*n9=new treenode{9,nullptr,nullptr},
             *n10=new treenode{10,nullptr,nullptr},*n11=new treenode{11,nullptr,nullptr},*n12=new treenode{12,nullptr,nullptr},
             *n13=new treenode{13,nullptr,nullptr},*n14=new treenode{14,nullptr,nullptr},*n15=new treenode{15,nullptr,nullptr},
             *n16=new treenode{16,nullptr,nullptr},*n17=new treenode{17,nullptr,nullptr},*n18=new treenode{18,nullptr,nullptr};

    //1
    root=n1;

    //2
    n1->firstchild=n2;
    n2->nextsibling=n3,n3->nextsibling=n4,n4->nextsibling=n5;

    //3
    n2->firstchild=n6;
    n6->nextsibling=n7,n7->nextsibling=n8;

    n3->firstchild=n9;
    n9->nextsibling=n10,n10->nextsibling=n11;

    n4->firstchild=n12;
    n12->nextsibling=n13;

    //4
    n6->firstchild=n14;
    n14->nextsibling=n15;

    n7->firstchild=n16;

    n8->firstchild=n17;

    n12->firstchild=n18;

void pre_root_traverse(treenode *rootnode)
{
    if(rootnode==nullptr)
    {
        return;
    }
    
    cout << rootnode->data << " ";
    treenode *child=rootnode->firstchild;

    while(child!=nullptr)
    {
        pre_root_traverse(child);
        child=child->nextsibling;
    }
}



int main(void)
{

    
    pre_root_traverse(root);
    return 0;
}
*/