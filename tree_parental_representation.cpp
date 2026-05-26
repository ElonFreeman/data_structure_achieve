#include<bits/stdc++.h>
using namespace std;
struct parentalnode
{
    char data;
    int parent_index;
};
struct parentalnode tree[10]={
            {'a',-1},
            {'b',1},
            {'c',1},
            {'d',2},
            {'e',2},
            {'f',2},
            {'g',3},
            {'h',3},
            {'i',4},
            {'j',4},};

int main(void)
{
    for(size_t i=0;i<size(tree);i++)
    {
        if(tree[i].parent_index==-1)
        {
            cout << "current:" << tree[i].data << ' ' 
             << "parent:" "NULL" << endl;
        }
        else
        {
            cout << "current:" << tree[i].data << ' ' 
             << "parent:" << tree[(tree[i].parent_index)-1].data << endl;
        }
    }

    return 0;
}