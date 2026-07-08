#include<bits/stdc++.h>
using namespace std;

int num_num;
vector<int> nums_sequece;

void shell_sort()
{
    for(int increment=num_num/2;increment>0;increment/=2)
    {
        for(int i=increment;i<num_num;i++)
        {
            int tmp=nums_sequece[i],j=0;
            for(j=i;j>=increment;j-=increment)
            {
                if(tmp<nums_sequece[j-increment])
                {nums_sequece[j]=nums_sequece[j-increment];}
                else
                {break;}
            }
            nums_sequece[j]=tmp;
        }
    }
}

int main(void)
{
    cin >> num_num; nums_sequece.resize(num_num);
    for(int i=0;i<num_num;i++)
    {cin >> nums_sequece[i];}

    shell_sort();
    for(int output:nums_sequece) {cout << output << ' ';} cout << endl;

    return 0;
}