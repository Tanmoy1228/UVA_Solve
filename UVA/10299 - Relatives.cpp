#include<bits/stdc++.h>
#define ll long long int
#define MAX 10000009
using namespace std;

ll phi_for_N(ll N)
{
    ll i,ans;
    ans=N;
    for(i=2; i*i<=N; i++)
    {
        if(N%i==0)
        {
            while(N%i==0)
            {
                N=N/i;
            }
            ans=ans-ans/i;///phi(N)=N(1- 1/p) where p is prime
        }
    }
    if(N>1)
        ans=ans-ans/N;
    return ans;
}

int main()
{
    ll n,m,i,j,ans;
    while(scanf("%lld",&n) && n)
    {
        ans=0;
        ans=phi_for_N(n);
        if(n==1)
            ans=0;
        printf("%lld\n",ans);

        //cout<<ans<<endl;
    }

    return 0;
}

