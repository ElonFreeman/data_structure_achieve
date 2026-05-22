#include<bits/stdc++.h>
using namespace std;

struct bt_node
{
    int data;
    bt_node *lchild,*rchild;
};

/*按照先序建立二叉树*/
void creat_bt_pre(bt_node **root)
{
    char data; cin >> data;

    if(data=='#') //”#“表示该位置无子树
    {
        *root=nullptr;
    }
    else
    {
        *root=new bt_node; //建立节点
        (*root)->data=data;
        creat_bt_pre(&((*root)->lchild));
        creat_bt_pre(&((*root)->rchild));
    } 
}

/*先序遍历*/
void preorder(bt_node *root)
{
    if(root==nullptr)
    {return;}
    
    cout << (char)(root->data) << ' '; //acess
    preorder(root->lchild); //遍历左子树
    preorder(root->rchild); //遍历右子树
}

/*中序遍历*/
void inorder(bt_node *root)
{
    if(root==nullptr)
    {return;}

    inorder(root->lchild); //遍历左子树
    cout << (char)(root->data) << ' '; //acess
    inorder(root->rchild); //遍历右子树
}

/*后序遍历*/
void postorder(bt_node *root)
{
    if(root==nullptr)
    {return;}

    postorder(root->lchild); //遍历左子树
    postorder(root->rchild); //遍历右子树
    cout << (char)(root->data) << ' '; //acess
}

/*层序遍历*/
void levelorder(bt_node *root)
{
    if(root==nullptr)
    {return;}

    deque<bt_node*> queue; //创建队列
    queue.push_back(root); //将root加入队列

    while(!queue.empty()) //当队列不为空
    {
        int quesize=size(queue); //记录当前队列长度
        for(int i=0;i<quesize;i++) //
        {
            bt_node* tmp=queue.front(); //访问当前节点
            cout << (char)(tmp->data) << ' ';
            queue.pop_front(); //当前节点出队
            

            if(tmp->lchild!=nullptr) //若当前节点有左子，则将其加入队列
            {
                queue.push_back(tmp->lchild);
            }
            if(tmp->rchild!=nullptr) //若当前节点有右子，则将其加入队列
            {
                queue.push_back(tmp->rchild);
            }
        }
    }
}


int main(void)
{
    bt_node *root=nullptr;
    
    creat_bt_pre(&root);
    preorder(root); cout << endl;
    inorder(root);  cout << endl;
    postorder(root);    cout << endl;
    levelorder(root);   cout << endl;

    return 0;
}

/*
    testset:A B D # # E # # C # F # #
*/