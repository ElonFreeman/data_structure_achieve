#include<bits/stdc++.h>
using namespace std;

int num_vertex,num_edge;
vector<bool> accessed_vertex;
vector<vector<bool>> accessed_edge;
vector<char> vertexs;
vector<vector<int>> edges;
struct kruskaledge
{
    int weight;
    bool lable;
    pair<int,int> advertex;
};
vector<kruskaledge> weightsort;

void prim_lowcost(int start) 
{
    // 1. 初始化 lowcost 数组，初值为起点到各点的边权
    // 用一个局部 vector 即可，大小为 num_vertex
    vector<int> lowcost(num_vertex);
    for(int i = 0; i < num_vertex; i++)
    {
        lowcost[i] = edges[start][i];
    }

    // 2. 初始化 parent 数组，用于记录树的边（替代你原来的 accessed_edge 查表）
    vector<int> parent(num_vertex, start); 

    // 起点加入生成树
    accessed_vertex[start] = true;
    lowcost[start] = 0; // 约定：lowcost 为 0 代表该点已加入生成树

    // 只需要循环 num_vertex - 1 次，找剩下的未知节点
    for(int count = 1; count < num_vertex; count++)
    {
        int minweight = INT_MAX;
        int next_vertex = -1;

        // 【循环 1】：找出当前未访问节点中，离树集合最近的点 (对应复杂度 O(V))
        for(int j = 0; j < num_vertex; j++)
        {
            if(accessed_vertex[j] == false && lowcost[j] < minweight)
            {
                minweight = lowcost[j];
                next_vertex = j;
            }
        }

        // 如果找不到有效边，说明图不连通
        if(next_vertex == -1) { return; }

        // 将选中的最短边记录到你的 accessed_edge 矩阵中（为了兼容你 main 函数的输出）
        int row = parent[next_vertex],col = next_vertex;
        accessed_edge[row][col] = accessed_edge[col][row] = true;

        // 将新节点标记为已访问，并将其移出待选集合
        accessed_vertex[next_vertex] = true;
        lowcost[next_vertex] = 0; 

        // 【循环 2】：因为新加入了 next_vertex，更新其他未访问点到树集合的最短距离 (对应复杂度 O(V))
        for(int j = 0; j < num_vertex; j++)
        {
            if(accessed_vertex[j] == false && edges[next_vertex][j] < lowcost[j])
            {
                lowcost[j] = edges[next_vertex][j];
                parent[j] = next_vertex; // 刷新 j 的“归属”，它是被 next_vertex 拉进来的
            }
        }
    }
}

void prim(int start) //row-based
{
    accessed_vertex[start]=true;
    int minweight=INT_MAX,row=-1,col=-1;
    for(int count=1;count!=num_vertex;count++)
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
        accessed_vertex[col]=true,accessed_edge[row][col]=true,accessed_edge[col][row]=true;
        minweight=INT_MAX;
    }
}

/*void kruskal()
{
    accessed_vertex[weightsort[0].advertex.first]=true,accessed_vertex[weightsort[0].advertex.second]=true;
    for(int count=1;count<num_edge;count++)
    {
        if(accessed_vertex[weightsort[count].advertex.first]!=accessed_vertex[weightsort[count].advertex.second])
        {
            accessed_vertex[weightsort[count].advertex.first]=true,accessed_vertex[weightsort[count].advertex.second]=true;
            weightsort[count].lable=true;
        }
    }
}*/

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
        weightsort.push_back({weight,false,{tail,head}});
        edges[tail][head]=edges[head][tail]=weight;
    }

    prim(0);
    for(int i=0;i<num_vertex;i++)
    {
        for(int j=0;j<num_vertex;j++)
        {
            if(i<j && accessed_edge[i][j]==true) {cout << '(' << i << ',' << j << ')' << endl;}
        }
    }
    accessed_vertex.resize(num_vertex,false),accessed_edge.assign(num_vertex,vector<bool>(num_vertex,false));

    /*sort(weightsort.begin(),weightsort.end(),[](const kruskaledge& a,const kruskaledge& b){return a.weight<b.weight;});
    kruskal();
    for(kruskaledge output:weightsort)
    {
        if(output.lable==true) {cout << '(' << output.advertex.first << ',' << output.advertex.second << ')' << endl;}
    }*/


    return 0;
}