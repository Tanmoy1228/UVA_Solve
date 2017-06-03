#include <stdio.h>
#define ll long long int
#define MX 1000009
//using namespace std;

ll check(ll mid)
{
    return (mid*(mid+1))/2;
}

ll binary(ll a)
{
    ll low,high,mid,ans;

    low=1;
    high=10000000000;
    ans=1;
    while(low<=high)
    {
        mid=(low+high)/2;
        ll aa=check(mid);
        if(aa<=a)
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
    ll t,T,i,j,ans,m,a,b;
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld",&a);

        ans=binary(a);

        printf("%lld\n",ans);
    }
    return 0;
}


