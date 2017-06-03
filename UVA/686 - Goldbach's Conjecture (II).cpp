#include<bits/stdc++.h>
#define ll long long int
#define MAX 100009
#define MOD 1000000007
using namespace std;
typedef pair<ll,ll>pii;

bool isPrime[MAX+5];
vector<ll> pr,prime;

void seive_N_logN(ll N)
{
    //calculate prime upto N in NlogN time
    memset(isPrime,true,sizeof isPrime);
    prime.clear();

    isPrime[1]=false;
    for (ll i = 4; i<= N; i=i+2)
        isPrime[i]=false;

    for (ll i = 3; i * i<= N; i=i+2)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
    for(ll i=1; i<MAX; i++)
        if(isPrime[i])
            prime.push_back(i);
}

int main()
{
    ll n,m,i,j,l,a,b,ans;
    seive_N_logN(MAX);
    while(scanf("%lld",&n) && n)
    {
        l=prime.size();
        ans=0;
        //cout<<prime.size()<<endl;
        for(i=0; i<l,prime[i]<=n/2 ;i++)
        {
            a=prime[i];
            b=n-a;
            if(isPrime[b])
            {
                ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

