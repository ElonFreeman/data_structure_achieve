#include<bits/stdc++.h>
using namespace std;

int num_vertex,num_edge;
vector<bool> access_lable;

void prim(vector<char>& vertexs,int start)
{

}

int main(void)
{
    cin >> num_vertex >> num_edge;
    vector<char> vertexs(num_vertex);
    vector<vector<int>> edges(num_vertex,vector(num_vertex,0));

    for(int i=0;i<num_vertex;i++)
    {
        cin >> vertexs[i]; access_lable.push_back(false);
    }
    for(int i=0;i<num_edge;i++) /*row-based*/
    {
        int tail,head,weight; cin >> tail >> head >> weight; edges[tail][head]=edges[head][tail]=1;
    }




    return 0;
}