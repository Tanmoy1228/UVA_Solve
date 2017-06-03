#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void binary(ll m,ll n)
{
    ll leftlow,lefthigh,rightlow,righthigh,midlow,midhigh;

    lefthigh=0;
    leftlow=1;
    righthigh=1;
    rightlow=0;

    while(1)
    {
        midhigh=lefthigh+righthigh;
        midlow=leftlow+rightlow;

//        cout<<midhigh<<" "<<midlow<<endl;

        if(midhigh*n==midlow*m)
            return;
        if(midhigh*n<midlow*m)
        {
            printf("R");
            lefthigh=midhigh;
            leftlow=midlow;
        }
        else
        {
            printf("L");
            righthigh=midhigh;
            rightlow=midlow;
        }
    }
}

int main()
{
    ll t,n,m,i,d;
    while(scanf("%lld %lld",&m,&n))
    {
        if(n==1 && m==1)
            break;
        binary(m,n);
        printf("\n");
    }
    return 0;
}

