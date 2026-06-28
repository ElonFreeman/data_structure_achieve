#include<bits/stdc++.h>
using namespace std;

void basical_trail_division(int num)
{
    vector<int> prime_factors;
    while(num%2==0)
    {
        num/=2;
        prime_factors.push_back(2);
    }

    for(int p=3;p<=num;p+=2)
    {
        while(num%p==0)
        {
            num/=p;
            prime_factors.push_back(p);
        }
    }

    for(int i=0;i<(prime_factors.end()-prime_factors.begin());i++)
    {
        cout << prime_factors[i] << ' ';
    }
}

void sieve_of_era(int num)
{
    vector<bool> marker(num+1,true);
    marker.at(0)=marker.at(1)=false;

    for(int p=2;p*p<=num;p++)
    {
        if(marker.at(p))
        {
            for(int i=p*p;i<=num;i+=p)
            {
                marker.at(i)=false;
            }
        }
    }

    vector<int> primes;
    for(int i=0;i<num+1;i++)
    {
        if(marker.at(i))
        {
            primes.push_back(i);
        }
    }

    for(int i:primes)
    {
        cout << i << ' ';
    }
}


int main(void)
{
    int num=100;

    basical_trail_division(num);
    sieve_of_era(num);

    return 0;
}