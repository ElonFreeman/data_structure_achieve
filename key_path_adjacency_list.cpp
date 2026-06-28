#include<bits/stdc++.h>
using namespace std;

int num_vertex,num_edge;
struct timesheet
{
    int ve,vl,e,l;
};
struct edge
{
    int index,weight;
    edge *next;
};
struct vertex
{
    char data;
    edge *first,*end;
};
vector<vertex> vertexs;
vector<timesheet> sheet;
vector<int> indegree;
vector<int> toposerial;


void find_indegree() //find th indegree of every vertex
{
    for(int i=0;i<num_vertex;i++) //traverse allof vertexs
    {
        edge *current=vertexs[i].first;
        while(current!=nullptr) //the indegree arctail 
        {indegree[current->index]++; current=current->next;}
    }
}

void topological_sort() //topological sort
{
    find_indegree();
    deque<int> topoqueue;
    for(int i=0;i<num_vertex;i++) //the vertex which indegree is zero,push it into queue
    {if(indegree[i]==0) {topoqueue.push_back(i);}}


    while(!(topoqueue.empty()))
    {
        edge *current=vertexs[topoqueue.front()].first;
        while(current!=nullptr)
        {
            indegree[current->index]--; //delete the arc
            if(indegree[current->index]==0) //the vertex which indegree is zero,push it into queue
            {topoqueue.push_back(current->index);}
            current=current->next; //move on
        }
        cout << vertexs[topoqueue.front()].data << ' '; topoqueue.pop_front(); //output the topo serial
    }
}

int main(void)
{
    cin >> num_vertex >> num_edge;
    vertexs.resize(num_vertex,{'\0',nullptr,nullptr}),sheet.resize(num_vertex,{0,0,0,0});
    for(int i=0;i<num_vertex;i++)
    {cin >> vertexs[i].data;}
    for(int i=0;i<num_edge;i++)
    {
        int tail,head,weight; cin >> tail >> head >> weight;
        edge *newedge=new edge;
        newedge->index=head,newedge->weight=weight,newedge->next=nullptr;
        if(vertexs[tail].first==nullptr)
        {vertexs[tail].first=newedge,vertexs[tail].end=newedge;}
        else
        {vertexs[tail].end->next=newedge,vertexs[tail].end=vertexs[tail].end->next;}
    }



    return 0;
}