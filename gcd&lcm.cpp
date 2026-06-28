#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a=36,b=24,gcd=0,lcm=0,origina=a,originb=b;
    while(a%b!=0)
    {
        int tmpa=a,tmpb=b;
        a=b;
        b=tmpa%tmpb;
    }

    gcd=b;
    lcm=(origina*originb)/gcd;

    cout << gcd << ' ' << lcm;

    return 0;
}