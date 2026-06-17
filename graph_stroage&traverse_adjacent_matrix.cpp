#include<bits/stdc++.h>
using namespace std;

vector<char> vertex;
vector<bool> access_lable;
int num_vertex,num_edge;

void BFS(vector<vector<int>>& edges,int start)  /*row-based*/
{
    deque<int> traverse_queue;
    traverse_queue.push_back(start),access_lable[start]=true;

    while(!(traverse_queue.empty()))
    {
        for(int i=0;i<num_vertex;i++)
        {
            if(edges[traverse_queue.front()][i]==1 && access_lable[i]==false)
            {
                traverse_queue.push_back(i),access_lable[i]=true;
            }
        }

        cout << vertex[traverse_queue.front()] << ' ';
        traverse_queue.pop_front();
    }
}

void DFS(vector<vector<int>>& edges,int start)
{
    cout << vertex[start] << ' ',access_lable[start]=true;

    for(int i=0;i<num_vertex;i++)
    {
        if(edges[start][i]==1 && access_lable[i]==false)
        {
            DFS(edges,i);
        }
    }
}

int main(void)
{
    cin >> num_vertex >> num_edge;
    vector<vector<int>> arcs(num_vertex,vector<int>(num_vertex,0));/*row:head,col:tail*/
    for(int i=0;i<num_vertex;i++)  //vertex
    {
        char value; cin >> value; vertex.push_back(value); access_lable.push_back(false);
    }
    for(int i=0;i<num_edge;i++)  //edge
    {
        int head_index,tail_index; cin >> head_index >> tail_index;  /*zero-based index*/
        arcs[head_index][tail_index]=1;
    }

    BFS(arcs,0); cout << endl;
    for(size_t i=0;i<size(access_lable);i++){access_lable[i]=false;}
    DFS(arcs,0); cout << endl;

    return 0;
}