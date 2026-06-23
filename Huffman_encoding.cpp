#include<bits/stdc++.h>
using namespace std;

int num_weight;
deque<float> weights_queue;
struct huffmannode
{
    float weight;
    int parentindex,leftchildindex,rightchildindex,lable;
};
vector<huffmannode> huffmantree;

void generate_huffmantree()
{
    while(!weights_queue.empty())
    {

    }
}

int main(void)
{
    cin >> num_weight; weights_queue.resize(num_weight); huffmantree.resize(2*num_weight-1);
    for(int i=0;i<num_weight;i++){cin >> weights_queue.at(i); huffmantree.at(i).weight=weights_queue.at(i);}
    sort(weights_queue.begin(),weights_queue.end(),[](int a,int b){return a<b;});


    return 0;
}