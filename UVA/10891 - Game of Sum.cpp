#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll rec(ll l, ll r)
{
    if(l>r)
        return -1*pow(10,10);
    if(l==r)
        return A[l];

    for(ll i=l;i<=r;i++)
    {

    }

}

int main()
{
    ll t,T,n,m,i,j,ans;
    while(scanf("%lld",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&A[i]);
        }
        ans=rec(1,n);
        printf("Case %lld: %lld\n",t,ans);

    }
    return 0;
}

