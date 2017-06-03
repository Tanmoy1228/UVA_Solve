#include<bits/stdc++.h>
#define ll long long int
#define MAX 2000009
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

    //isPrime[1]=false;
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
    ll n,c,i,j,l,a,b,m;
    seive_N_logN(MAX);
    //twinPrime();
    while(scanf("%lld %lld",&n,&c)!=EOF)
    {
        for(i=0;i<prime.size();i++)
        {
            if(prime[i]>n)
                break;
        }
        if(i%2==0)
            c=2*c;
        else
            c=2*c-1;

        j=max( (ll) 0, (i-c)/2 );
        m=i;

        printf("%lld %lld:",n,(c+1)/2);

        for(i=j;i<min(j+c, m); i++)
            printf(" %lld",prime[i]);
        printf("\n\n");
    }
    return 0;
}

