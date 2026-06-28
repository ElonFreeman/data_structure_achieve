#include<bits/stdc++.h>
using namespace std;

vector<int> sieve_of_eratosthenes(int end)
{
    vector<bool> isprime(end+1,true);  //marker set intalized as true
    isprime.at(0)=isprime.at(1)=false;  //zero and one is not prime  
    
    for(int p=2;p*p<=end;p++)  //p:origin nums
    {
        if(isprime.at(p))  //not deleted nums that is prime
        {
            for(int i=p*p;i<=end;i+=p)  //i:multiples
            {
                isprime.at(i)=false;  //delete the multiples
            }
        }
    }

    vector<int> primes;
    for(int p=0;p<=end;p++)  //scan the nums and output
    {
        if(isprime.at(p))
        {
            primes.push_back(p);
        }
    }

    return primes;
}

vector<long long> trail_division(long long num)  //basic tail divi
{
    vector<long long> factors;
    
    while(num%2==0)  //process even factor
    {
        factors.push_back(2);
        num/=2;
    }

    for(int i=3;i<=sqrt(num);i+=2)  //process odd factor
    {
        while(num%i==0)
        {
            factors.push_back(i);
            num/=i;
        }
    }

    return factors;
}

int main(void)
{
    vector<int> arr;
    int begin=2,end=30;
    
    vector<int> primes=sieve_of_eratosthenes(end);

    for(int i=0;i<(primes.end()-primes.begin());i++)
    {
        cout << primes.at(i) << ' ';
    }

    return 0;
}