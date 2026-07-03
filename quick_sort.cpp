#include<bits/stdc++.h>
using namespace std;

void quick_sort(int l,int r,vector<int> *arr)
{
    if(l==r) return; //拆分到只有一个元素时返回，一个元素的集不会进下面的并操作

    int i=l-1,j=r+1,mid=(*arr)[(l+r)/2]; //定位中点元素

    /*在当前序列中进行中点两侧的操作，交换中点两侧符合条件的元素，直到i,j相遇*/
    while(i<j)
    {
        /*找中点元素左侧大于中点元素的，找到后停止*/
        do
        {
            i++;

        } while((*arr)[i]<mid);
        /*找中点元素右侧小于中点元素的，找到后停止*/
        do
        {
            j--;

        } while((*arr)[j]>mid);

        /*如果上面找到的两个元素的位置符合i<j,交换位置，即把大的换到后面，小的换到前面*/
        if(i<j) 
        {
            swap((*arr)[i],(*arr)[j]);
        }
    }

    /*二等分割数组*/
    quick_sort(l,j,arr); //左侧
    quick_sort(j+1,r,arr); //右侧
}

int main(void)
{
    vector<int> arr={9,1,7,6,6,3,2,8};

    quick_sort(0,size(arr)-1,&arr);
    
    for(int output:arr)
    {
        cout << output <<' ';
    }
    cout << endl;

    return 0;
}