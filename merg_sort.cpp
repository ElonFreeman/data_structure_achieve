#include<bits/stdc++.h>
using namespace std;

void merg_sort(int l,int r,vector<int> *arr_a,vector<int> *arr_b)
{
    if(l==r) return; //拆分到只有一个元素时返回，一个元素的集不会进行归并操作

    /*二等分割数组*/
    int mid=(l+r)/2;
    merg_sort(l,mid,arr_a,arr_b); //左侧
    merg_sort(mid+1,r,arr_a,arr_b); //右侧

    /*归并操作*/
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r)
    {
        if((*arr_a)[i]<=(*arr_a)[j])
        {
            (*arr_b)[k++]=(*arr_a)[i++];
        }
        else
        {
            (*arr_b)[k++]=(*arr_a)[j++];
        }
    }

    /*单侧剩余填充*/
    while(i<=mid) //左侧剩余
    {
        (*arr_b)[k++]=(*arr_a)[i++];
    }
    while(j<=r) //右侧剩余
    {
        (*arr_b)[k++]=(*arr_a)[j++];
    }

    /*覆盖原数组相同区域*/
    for(int i=l;i<=r;i++)
    {
        (*arr_a)[i]=(*arr_b)[i];
    }
}

int main(void)
{
    vector<int> arr_a={9,1,7,6,6,3,2,8},arr_b(size(arr_a)); //arr_b:辅助空间

    merg_sort(0,size(arr_a)-1,&arr_a,&arr_b);

    for(int output:arr_a)
    {
        cout << output << ' ';
    }
    cout << endl;

    return 0;
}