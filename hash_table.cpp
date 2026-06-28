/*

 ======================================
 *  键生成算法：BKDR哈希                 *
 *  哈希函数：基于除留余数法              *
 *  哈希抗冲突算法:开放定址线性探测再散列   *
 ======================================

 */


#include<bits/stdc++.h>
using namespace std;

//random_device rd; mt19937 gen(rd()); uniform_int_distribution<> distr(1,100); //init random num generator

int num_element,table_length;
vector<string> elements;
vector<long int> keys;
vector<string> bucket;
vector<bool> conflict_lable;

void generate_key()
{
    for(int i=0;i<num_element;i++)
    {
        long int key = 0;
        for(char c : elements[i])
        {
            key = key * 131 + (long int)c;  // 131 是常用质数
        }
        keys[i] = key;
    }
}

long int findlable_len(int num_element)
{
    long int prime=num_element;
    int flag=0;
    while(flag==0)
    {
        long int current=prime;
        int sentinel=0;
        if(current%2==0)
        {
            sentinel=1;
        }
        for(int i=3;i<=sqrt(current);i+=2)
        {
            if(current%i==0)
            {
                sentinel=1; break;
            }
        }
        if(sentinel==0)
        {
            flag=1;
        }
        else
        {
            prime++; continue;
        }
    }
    
    return prime;
}

long int rehash(int hash) //Open Adressing: Linear Probing Rehashing
{
    int incremental=1,hashsec=hash;
    while(conflict_lable[hashsec]==true)
    {
        hashsec=(hash+incremental)%size(bucket); incremental++;
    }
    return hashsec;
}

void hash_func()
{
    long int divisor=table_length;
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

void hash_search()
{
    string element;
    while(1)
    {
        cin >> element;
        if(element=="exit"){break;}

        long int key = 0;
        for(char c : element)
        {
            key = key * 131 + c;  // 131 是常用质数
        }
        //cout << key << endl;
        long int hash=key%table_length;
        int incremental=1;
        while(bucket[hash]!=element)
        {
            hash=(hash+incremental)%size(bucket);
            incremental++;
            printf("\r%d",incremental);
        }
        //cout << "bingo" << endl;

        cout << hash << ' ' << bucket[hash] << endl;
    }
}

int main(void)
{
    cin >> num_element; elements.resize(num_element),keys.resize(num_element);
    table_length=findlable_len(num_element); bucket.resize(table_length),conflict_lable.resize(table_length);
    for(int i=0;i<num_element;i++)
    {cin >> elements[i];}

    generate_key();
    hash_func();
    cout << endl;
    for(string output:bucket){cout << output << endl;}cout << endl;
    hash_search();

    //return 0;
}


/*
5
apple
banana
cat
dog
elephant

17
a
b
c
d
e
f
g
h
i
j
k
l
m
n
o
p
q

20
apple
application
apply
app
appetite
applaud
applepie
apricot
april
apron
apt
aqua
aquarium
arab
arbitrary
arc
arch
area
arena
argue

10
test
testing
tester
tested
testify
testament
testicle
testify
testosterone
testudo
*/