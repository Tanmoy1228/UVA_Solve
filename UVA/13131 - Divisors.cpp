#include <bits/stdc++.h>

using namespace std;
#define ll long long int

ll oo(ll n,ll k)
{
    ll i,j,o,ans=0;;
    for(i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            if(i%k!=0)
                ans+=i;
            if(n/i!=i && (n/i)%k!=0 )
                ans+=(n/i);

        }
    }
    return ans;

}
int main()
{

    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll T,t,i,n,k;
    scanf("%lld",&T);
//    ppp(MX);
    for(t=1; t<=T; t++)
    {
        scanf("%lld %lld",&n,&k);
        if(k==1)
        {
            printf("0\n");
            continue;
        }
        ll ans=oo(n,k);
        printf("%lld\n",ans);
    }

    return 0;
}


