
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

map<ll,ll>dp;
ll n;

ll rec(ll m)
{
    ll i,j;

    for(i=1;i<100;i++)
    {
        if(i%2)
            m*=9;
        else
            m*=2;
        if(m>=n)
            return i%2;
    }
}

int main()
{
    ll t,T,m,i,j,ans;
    while(scanf("%lld",&n)!=EOF)
    {
        if(rec(1))
            printf("Stan wins.\n");
        else
            printf("Ollie wins.\n");
    }
    return 0;
}
