#include<bits/stdc++.h>
#include <system_error>
using namespace std;

struct childs
{
    int index;
    childs *nextchild;
};

struct parents
{
    char data;
    childs *firstchild;
};

struct childs node_a[2]={{2,&node_a[1]},{3,nullptr}},
              node_b[3]={{4,&node_b[1]},{5,&node_b[2]},{6,nullptr}},
              node_c[2]={{7,&node_c[1]},{8,nullptr}},
              node_d[2]={{9,&node_d[1]},{10,nullptr}};

struct parents parent[10]={
                        {'a',&node_a[0]},
                        {'b',&node_b[0]},
                        {'c',&node_c[0]},
                        {'d',&node_d[0]},
                        {'e',nullptr},
                        {'f',nullptr},
                        {'g',nullptr},
                        {'h',nullptr},
                        {'i',nullptr},
                        {'j',nullptr}};

int main(void)
{
    for(size_t i=0;i<size(parent);i++)
    {
        cout << "current:" << parent[i].data << ' ';

        childs *current=parent[i].firstchild;
        for(size_t j=1;current!=nullptr;j++)
        {
            cout << "child" << j << ':' <<  parent[(current->index)-1].data << ' ';
            current=current->nextchild;
        }
        cout << endl;
    }

    return 0;
}

