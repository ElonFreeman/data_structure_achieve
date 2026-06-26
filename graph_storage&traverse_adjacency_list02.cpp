#include<bits/stdc++.h>
#include <exception>
using namespace std;

struct edge
{
    int index;
    edge *next;
};
struct  vertex
{
    char data;
    edge *firstedge,*end;
};

int num_vertex,num_edge;
vector<bool> access_lable;

void BFS(vector<vertex>& vertexs,int start)
{
    deque<int> traverse_queue;
    traverse_queue.push_back(start); access_lable[start]=true;

    while(!(traverse_queue.empty()))
    {
        edge *current=vertexs[traverse_queue.front()].firstedge;
        while(current!=nullptr)
        {
            if(access_lable[current->index]==false)
            {
                traverse_queue.push_back(current->index); access_lable[current->index]=true;
            }
            current=current->next;
        }

        cout << vertexs[traverse_queue.front()].data << ' '; traverse_queue.pop_front();
    }
}

void DFS(vector<vertex>& vertexs,int start)
{
    cout << vertexs[start].data << ' '; access_lable[start]=true;

    edge *current=vertexs[start].firstedge;
    while(current!=nullptr)
    {
        if(access_lable[current->index]==false)
        {
            DFS(vertexs,current->index);
        }

        current=current->next;
    }
}

int main(void)
{
    cin >> num_vertex >> num_edge;
    vector<vertex> vertexs(num_vertex);

    for(int i=0;i<num_vertex;i++)
    {cin >> vertexs[i].data; vertexs[i].firstedge=nullptr; access_lable.push_back(false);}
    for(int i=0;i<num_edge;i++)
    {
        int index_tail,index_head; cin >> index_tail >> index_head;

        edge *node=new edge; node->index=index_head; node->next=nullptr;
        if(vertexs[index_tail].firstedge==nullptr)
        {vertexs[index_tail].firstedge=node; vertexs[index_tail].end=node;}
        else
        {vertexs[index_tail].end->next=node; vertexs[index_tail].end=vertexs[index_tail].end->next;}
    }

    BFS(vertexs,0); cout << endl;
    for(size_t i=0;i<size(access_lable);i++){access_lable[i]=false;}
    DFS(vertexs,0); cout << endl;

    return 0;
}