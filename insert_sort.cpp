#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int num_num; cin >> num_num;
    vector<int> seq(num_num);
    for(int i=0;i<num_num;i++)
    {cin >> seq[i];}

    for(int i=1;i<size(seq);i++) //从第二个元素开始遍历无序列，第一个元素看作有序列
    {
        int key=seq[i],j=i-1,tmp=0; //
        while(j>0 && seq[j]>key) //遍历有序列部分
        {seq[j+1]=seq[j],j--,tmp=j;}
        seq[tmp+1]=key;
    }

    return 0;
}