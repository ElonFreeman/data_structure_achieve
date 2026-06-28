#include<bits/stdc++.h>
using namespace std;

//random_device rd; mt19937 gen(rd()); uniform_int_distribution<> distr(1,100); //init random num generator

int num_element,divisor;
vector<string> elements;
vector<long int> keys;
vector<string> bucket;
vector<bool> conflict_lable;

void generate_key()
{
    for(int i=0;i<num_element;i++)
    {
        keys[i]=elements[i][0]+elements[i][size(elements[i])-1];
    }
}

long int rehash(int hash) //Open Adressing: Linear Probing Rehashing
{
    int incremental=1,hashsec=hash;
    while(conflict_lable[hashsec]==true)
    {
        hashsec=(hash+incremental)%size(bucket);
        incremental++;
    }
    return hashsec;
}

void hash_func()
{
    int divisor=17;
    bucket.resize(divisor),conflict_lable.resize(divisor);
    for(int i=0;i<num_element;i++)
    {
        long int hash=keys[i]%divisor;
        if(conflict_lable[hash]==false)
        {
            bucket[hash]=elements[i]; conflict_lable[hash]=true;
        }
        else
        {
            hash=rehash(hash);
            bucket[hash]=elements[i]; conflict_lable[hash]=true;
        }
    }
}

/*void hash_search()
{
    string element;
    while(1)
    {
        cin >> element;
        long int key=element[0]+element[size(element)-1];
        long int hash=key%17;

        cout << hash << ' ' << bucket[hash] << endl;
    }
}*/

int main(void)
{
    cin >> num_element;
    divisor=(num_element);
    for(int i=0;i<num_element;i++)
    {cin >> elements[i];}

    generate_key();
    hash_func();


    return 0;
}