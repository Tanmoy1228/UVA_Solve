#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll A[1005],total,n,m;

bool check(ll mid)
{
    ll i,j;
    for(i=1,j=1;i<=m;i++)
    {
        ll cont=mid;
        while(cont>=A[j] && j<=n)
        {
            cont-=A[j];
            j++;
        }
    }
    if(j==n+1)
        return true;
    else
        return false;
}

ll Binary_Search()
{
    ll b,e,mid,ans;
    b=0;
    e=total;

    while(b<=e)
    {
        mid=(b+e)/2;
        if(check(mid))
            e=mid-1,ans=mid;
        else
            b=mid+1;
    }
    return ans;
}

int main()
{
    ll i,ans;
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        total=0;
        for(i=1; i<=n; i++)
            scanf("%lld",&A[i]),total+=A[i];
        ans=Binary_Search();
        printf("%lld\n",ans);
    }
    return 0;
}
