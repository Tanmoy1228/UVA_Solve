#include <bits/stdc++.h>
#define ll long long int

using namespace std;
ll A[100009],n;
ll upbinary(ll a)
{
    ll i,low,high,mid,ans;

    low=1;
    high=n;
    ans=1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(A[mid]>a)
        {
            high=mid-1;
            ans=mid;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}

ll lowbinary(ll a)
{
    ll i,low,high,mid,ans;

    low=1;
    high=n;
    ans=1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(A[mid]<a)
        {
            low=mid+1;
            ans=mid;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}

int main()
{
    ll t,m,i,a,ans;
    while(scanf("%lld",&n)!=EOF)
    {
        A[1]=-5;
        for(i=2; i<=n+1; i++)
            scanf("%lld",&A[i]);
        A[i]=powl(10,15);
        n=n+2;
        scanf("%lld",&m);
        for(i=1; i<=m; i++)
        {
            scanf("%lld",&a);
            ans=lowbinary(a);
            if(A[ans]<0)
                printf("X ");
            else
                printf("%lld ",A[ans]);
            ans=upbinary(a);
            if(A[ans]==powl(10,15))
                printf("X\n");
            else
                printf("%lld\n",A[ans]);
        }

    }
    return 0;
}

