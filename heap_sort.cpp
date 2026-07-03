#include<bits/stdc++.h>
using namespace std;

int num_element;
vector<int> heap;

void sift_up(int index)
{

}
void sift_down(int index)
{
    int parent=index; 
    while(parent*2+1<num_element)
    {
        int leftch=parent*2+1,rightch=parent*2+2,maxch=leftch;
        if(rightch<num_element && heap[rightch]>heap[leftch])
        {
            maxch=rightch;
        }
        if(heap[parent]<heap[maxch])
        {
            swap(heap[parent],heap[maxch]); parent=maxch;
        }
        else
        {break;}        
    }
}

void generate_heap() //max-heap
{
    for(int index=num_element/2-1;index>=0;index--)
    {
        sift_down(index);
    }
}

void heap_sort()
{
    vector<int> seq_serial;
    while(!heap.empty())
    {
        swap(heap.front(),heap.back());
        seq_serial.push_back(heap.back()); heap.pop_back(); num_element--;
        sift_down(0);
    }

    for(int output:seq_serial)
    {cout << output << ' ';}
}

int main(void)
{
    cin >>num_element; heap.resize(num_element);
    for(int &input:heap) {cin >> input;}

    generate_heap();
    heap_sort(); cout << endl;


    return 0;
}