#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll binary(ll d,ll n)
{
    ll i,mid,ans;

    mid=n;
    ans=1;
    for(i=1;i<d;i++)
    {
//        cout<<ans<<" "<<mid<<endl;
        if((mid/2)==(mid+1)/2)
        {
            mid=mid/2;
            ans=2*ans+1;
        }
        else
        {
            mid=(mid+1)/2;
            ans=2*ans;
        }
    }
    return ans;
}

int main()
{
    ll t,n,m,i,d;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&d,&n);
        ll ans=binary(d,n);
        printf("%lld\n",ans);
    }
    scanf("%lld",&t);
    return 0;
}
