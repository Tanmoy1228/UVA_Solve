#include <bits/stdc++.h>
using namespace std;

#define MX 100009
#define ll long long int

bool isp[MX+5];
ll phi[MX+5];


void ppp(ll n)
{
    ll i,j;
    memset(isp,true,sizeof isp);
//    prime.clear();
    isp[1]=false;
    for(i=4; i<=n; i=i+2)
        isp[i]=false;
    for(i=3; i*i<=n; i=i+2)
    {
        if(isp[i])
        {
            for(j=i*i; j<=n; j=j+i)
            {
                isp[j]=false;
            }
        }
    }

}

void ppo(ll n)
{
    ll i,j,k;
    ppp(MX);
    for(i=1; i<=n; i++)
        phi[i]=i;
    for(i=2; i<=n; i++)
    {
        if(isp[i])
            for(j=i; j<=n; j+=i)
                phi[j]-=phi[j]/i;
    }
}

int main()
{
    ll T,t,n;
    scanf("%lld",&T);
    ppp(MX);
    ppo(MX);
    for(t=1;t<=T;t++)
    {
        scanf("%lld",&n);
        ll a=phi[n];
        printf("%lld\n",a);
    }
    return 0;
}
