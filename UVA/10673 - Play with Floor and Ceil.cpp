#include<bits/stdc++.h>
#define ll long long int
#define MAX 10000009
using namespace std;
int main()
{
    ll n,m,i,j,ans,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        ans=0;
        ans=n%m;
        printf("%lld %lld\n",m-ans,ans);
    }

    return 0;
}

