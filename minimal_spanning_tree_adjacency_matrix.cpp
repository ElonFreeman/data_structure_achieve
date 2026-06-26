#include<bits/stdc++.h>
using namespace std;

int num_vertex,num_edge;
vector<bool> accessed_vertex;
vector<vector<bool>> accessed_edge;
vector<char> vertexs;
vector<vector<int>> edges;
deque<int> access_queue;

void prim(int start) //row-based
{
    accessed_vertex[start]=true;
    int count=1,minweight=INT_MAX,row=-1,col=-1;
    while(count!=num_vertex)
    {
        for(int i=0;i<num_vertex;i++) //traverse the vertex which is accessed
        {
            if(accessed_vertex[i]==true)
            {
                for(int j=0;j<num_vertex;j++) //the accessed vertex's edge in adjacency matrix
                {
                    if(edges[i][j]<minweight && edges[i][j]!=0 && accessed_vertex[j]==false && accessed_edge[i][j]==false)
                    {
                        minweight=edges[i][j]; row=i,col=j;
                    }
                }
            }
        }

        if(row==-1 || col==-1) {return;}
        accessed_vertex[col]=true,accessed_edge[row][col]=true,accessed_edge[col][row]=true,count++;
        minweight=INT_MAX;
    }
}

void kruskal(int start)
{

}

int main(void)
{
    cin >> num_vertex >> num_edge;
    vertexs.resize(num_vertex),edges.assign(num_vertex,vector<int>(num_vertex,INT_MAX));
    accessed_vertex.resize(num_vertex,false),accessed_edge.assign(num_vertex,vector<bool>(num_vertex,false));
    for(int i=0;i<num_vertex;i++)
    {cin >> vertexs[i];}
    for(int i=0;i<num_edge;i++) //row-based
    {
        int tail,head,weight; cin >> tail >> head >> weight;
        edges[tail][head]=edges[head][tail]=weight;
    }

    prim(0);
    for(int i=0;i<num_vertex;i++)
    {
        for(int j=0;j<num_vertex;j++)
        {
            if(accessed_edge[i][j]==true) {cout << '(' << i << ',' << j << ')' << endl;}
        }
    }
    accessed_vertex.resize(num_vertex,false),accessed_edge.assign(num_vertex,vector<bool>(num_vertex,false));

    kruskal(0);


    return 0;
}