#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int index,weight;
    edge *next;
};
struct vertex
{
    char data;
    edge *firstedge,*end;
};
int num_vertex,num_edge;
vector<bool> access_lable;

void prim(vector<vertex>& vertexs,int start)
{
    edge *current=vertexs[start].firstedge; access_lable[start]=true;
    int minimumedge=current->index;

    for(int i=0;i<num_vertex;i++)
    {
        while(current!=nullptr)
        {
            if((current->weight)<minimumedge && access_lable[current->index]==false)
            {
                minimumedge=current->index;
            }

            current=current->next;
        }

        if(access_lable[minimumedge]==false)
        {
            access_lable[minimumedge]=true;

        }
    }
    
}

void kruskal(vector<vertex>& vertexs,int start)
{

}

int main(void)
{
    cin >> num_vertex >> num_edge;
    vector<vertex> vertexs(num_vertex);
    for(int i=0;i<num_vertex;i++)
    {
        cin >> vertexs[i].data; vertexs[i].firstedge=nullptr; access_lable[i]=false;
    }
    for(int i=0;i<num_edge;i++)
    {
        int tail,head,weight; cin >> tail >> head >> weight;
        if(vertexs[tail].firstedge==nullptr)
        {
            edge *newedge=new edge;
            newedge->index=head; newedge->weight=weight; newedge->next=nullptr; 
            vertexs[tail].firstedge=newedge; vertexs[tail].end=newedge;
        }
        else
        {
            edge *newedge=new edge;
            newedge->index=head; newedge->weight=weight; newedge->next=nullptr;
            vertexs[tail].end->next=newedge; vertexs[tail].end=vertexs[tail].end->next;
        }
    }

    prim(vertexs,0);
    for(size_t i=0;i<size(access_lable);i++){access_lable[i]=false;}
    kruskal(vertexs,0);

    return 0;
}