#include<bits/stdc++.h>
#define ll long long int
#define MAX 20000009
#define MOD 1000000007
using namespace std;
typedef pair<ll,ll>pii;

bool isPrime[MAX+5];
vector<ll> pr,prime;
vector<pii>ans;

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

void twinPrime()
{
    ans.clear();
    ll i,a,l;
    l=prime.size();
    for(i=0;i<l;i++)
    {
        a=prime[i];
        if( isPrime[a+2] )
            ans.push_back( make_pair(a,a+2) );
    }
    return;
}


int main()
{
    ll n,m,i,j,l,a,b;
    seive_N_logN(MAX);
    twinPrime();
    while(scanf("%lld",&n)!=EOF)
    {
        a=ans[n-1].first;
        b=ans[n-1].second;
        printf("(%lld, %lld)\n",a,b);
    }
    return 0;
}
