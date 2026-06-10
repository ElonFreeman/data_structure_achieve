#include<bits/stdc++.h>
using namespace std;

vector<bool> access_lable;
int num_vertex=0,num_edge=0;

struct edge
{
    int index;
    edge *next;
};

struct vertexnode
{
    char data;
    edge *first_edge,*end;
};

void build_graph(vertexnode *nodes)
{
    for(int i=0;i<num_vertex;i++)
    {
        cin >> nodes[i].data,
        nodes[i].first_edge=nullptr,
        nodes[i].end=nodes[i].first_edge;
        access_lable.push_back(false);
    }

    for(int i=0;i<num_edge;i++)
    {
        int head,adjp_index; cin >> head >> adjp_index;
        edge *newedge=new edge;
        newedge->index=adjp_index,newedge->next=nullptr;

        if(nodes[head].first_edge==nullptr)
        {nodes[head].first_edge=newedge,nodes[head].end=newedge;}
        else
        {nodes[head].end->next=newedge,nodes[head].end=newedge;}
    }
}

void output_graph(vertexnode *nodes)
{
    for(int i=0;i<num_vertex;i++)
    {
        cout << nodes[i].data << ' ';
        edge *current=nodes[i].first_edge;
        while(current!=nullptr)
        {
            cout << nodes[current->index].data << ' ';
            current=current->next;
        }
        cout << endl;
    }
}

void BFS(vector<vertexnode>& vertexlist,int begin_vertex)  //paraments:vertexlist and begin vertex index
{
    deque<int> bfs_queue;  //setup a access queue,strore vertex index
    bfs_queue.push_back(begin_vertex);  //beginner push into queue
    access_lable[begin_vertex]=true;  //access lable set into true

    while(!(bfs_queue.empty()))  //if queue is empty
    {
        int index_fornt=bfs_queue.front();  //first element in the queue
        cout << vertexlist[bfs_queue.front()].data << ' ';  //output
        bfs_queue.pop_front();  //popout

        edge *current=(vertexlist[index_fornt]).first_edge;  //a pointer to first edge of current vertex
        while(current!=nullptr)  //traverse adjacent vertex index linked list
        {
            if(access_lable[current->index]==false)  //if vertex not accessed
            {
                bfs_queue.push_back(current->index);  //push into queue
                access_lable[current->index]=true;  //access lable set into true
            }
            current=current->next;  //move on
        }        
    }
}

void DFS(vector<vertexnode>& vertexlist,int begin_index)  //paraments:vertexlist and begin vertex index
{
    cout << vertexlist[begin_index].data << ' ';  //output
    access_lable[begin_index]=true;  //popout
    
    edge *current=vertexlist[begin_index].first_edge;  //a pointer to first edge of current vertex
    while(current!=nullptr)  //traverse adjacent vertex index linked list
    {
        if(access_lable[current->index]==false)  //if vertex not accessed
        {
            DFS(vertexlist,current->index);  //recursion,based on index,pass on whole vertex list
        }

        current=current->next;  //move on
    }
}

int main(void)
{
    cin >> num_vertex >> num_edge;
    vector<vertexnode> vertexlist(num_vertex);
    
    build_graph(&vertexlist[0]);
    output_graph(&vertexlist[0]); cout << endl;

    BFS(vertexlist,0); cout << endl;
    for(size_t i=0;i<size(access_lable);i++) {access_lable[i]=false;}  //reset access lables
    DFS(vertexlist,0); cout << endl;

    return 0;
}