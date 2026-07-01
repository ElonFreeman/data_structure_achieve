#include<bits/stdc++.h>
using namespace std;

int num_element;
vector<int> heap;

void sift_up(int index)
{
    int leftch=index*2,rightch=index*2+1,largest=index;
    
}
void generate_heap() //max-heap
{
    for(int index=num_element/2-1;index>=0;index--)
    {
        sift_up(index);
    }
}

void heap_sort()
{

}

int main(void)
{
    cin >>num_element; heap.resize(num_element);
    for(int &input:heap) {cin >> input;}




    return 0;
}