#include<bits/stdc++.h>
using namespace std;

int num_element;
vector<int> heap;
priority_queue<int> pri_que;
void sift_up(int index)
{

}
void sift_down(int index) //下滤：基于索引
{
    int parent=index; //初始化
    while(parent*2+1<num_element) //边界：当前父存在左子
    {
        int leftch=parent*2+1,rightch=parent*2+2,maxch=leftch; //0-based编址，定义左子和右子的索引，默认左子为最大子
        if(rightch<num_element && heap[rightch]>heap[leftch]) //若右子存在且右子大于左子，重定义最大值为右子
        {
            maxch=rightch;
        }
        if(heap[parent]<heap[maxch]) //若父小于最大子，交换，并更新父为最大子
        {
            swap(heap[parent],heap[maxch]); parent=maxch;
        }
        else //若父大于最大子，则break recycle,不必继续向下，因为子树必定符合堆序
        {break;}        
    }
}

void generate_heap() //建堆，建立大顶堆
{
    for(int index=num_element/2-1;index>=0;index--) //从最后一个父节点开始执行下滤
    {
        sift_down(index);
    }
}

void heap_sort()
{
    vector<int> seq_serial;
    while(!heap.empty())
    {
        swap(heap.front(),heap.back()); //堆定与堆尾交换
        seq_serial.push_back(heap.back()); heap.pop_back(); num_element--; //堆尾进入序列，更新堆长
        sift_down(0); //下滤：重建堆序
    }

    for(int output:seq_serial)
    {cout << output << ' ';}
}

int main(void)
{
    cin >>num_element; heap.resize(num_element);
    for(int i=0;i<num_element;i++)
    {int input;cin >> input; heap[i]=input,pri_que.push(input);}
    
    for(int i=0;i<num_element;i++)
    {cout << pri_que.top() << ' '; pri_que.pop();} cout << endl;

    generate_heap();
    heap_sort(); cout << endl;


    return 0;
}