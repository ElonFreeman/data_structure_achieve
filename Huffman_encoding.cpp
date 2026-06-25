#include<bits/stdc++.h>
using namespace std;

int num_weight; 
struct huffmannode
{
    int weight,parent,leftc,rightc,lable;
};
vector<huffmannode> huffmantree;
vector<char> commands;

void generate_huffmantree()
{
    while(huffmantree.size()<(size_t)(2*num_weight-1))
    {
        int index1,index2,min1=INT_MAX,min2=INT_MAX;
        for(size_t i=0;i<size(huffmantree);i++)
        {
            if(huffmantree[i].weight<min1 && huffmantree[i].lable==0)
            {
                min1=huffmantree[i].weight,index1=i;
            }
        }
        huffmantree[index1].lable=1;
        for(size_t i=0;i<size(huffmantree);i++)
        {
            if(huffmantree[i].weight<min2 && huffmantree[i].weight>=min1 && huffmantree[i].lable==0)
            {
                min2=huffmantree[i].weight,index2=i;
            }
        }
        huffmantree[index2].lable=1;

        huffmantree.push_back({min1+min2,0,index1+1,index2+1,0});
        huffmantree[index1].parent=size(huffmantree),huffmantree[index2].parent=size(huffmantree);
    }
}

void inorder(size_t root_index)
{
    if(root_index==0) {return;}
    inorder(huffmantree[root_index-1].leftc);
    cout << huffmantree[root_index-1].weight << ' ';
    huffmantree[huffmantree[root_index-1].leftc].lable=1,huffmantree[huffmantree[root_index-1].rightc].lable=0;
    inorder(huffmantree[root_index-1].rightc);
}

void encoding()
{
    for(int i=0;i<num_weight;i++)
    {
        vector<int> encode;
        int current=i;
        while(huffmantree[current].parent!=0)
        {
            int parent=huffmantree[current].parent-1;
            if(huffmantree[parent].leftc==current+1)
            {encode.push_back(0);}
            else if(huffmantree[parent].rightc==current+1)
            {encode.push_back(1);}
            current=parent;
        }
        reverse(encode.begin(),encode.end());

        cout << commands[i] << ':';
        for(int output:encode)
        {
            cout << output;
        }
        cout << endl;
    }
}

int main(void)
{
    cin >> num_weight; huffmantree.resize(num_weight),commands.resize(num_weight);
    for(int i=0;i<num_weight;i++)
    {
        cin >> huffmantree[i].weight >> commands[i];
        huffmantree[i].parent=huffmantree[i].leftc=huffmantree[i].rightc=huffmantree[i].lable=0;
    }
    cout << endl;

    generate_huffmantree();
    for(huffmannode output:huffmantree)
    {
        cout << output.weight << ' ' << output.parent << ' ' << output.leftc << ' ' << output.rightc << ' ' << output.lable << endl;
    }
    cout << endl;

    inorder(size(huffmantree));
    cout << endl << endl;

    encoding();

    return 0;
}