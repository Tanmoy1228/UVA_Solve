#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000009
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
            for (ll j = i * i; j <= N; j += i+i)
                isPrime[j] = false;
        }
    }
    for(ll i=1; i<MAX; i++)
        if(isPrime[i])
            prime.push_back(i);
}


int main()
{
    ll n,m,i,j,l,a,b;
    seive_N_logN(MAX);
    l=prime.size();
    while(scanf("%lld",&n)!=EOF)
    {
        if(n%2)
        {
            if(isPrime[n-2] && n!=1)
                printf("%lld is the sum of 2 and %lld.\n",n,n-2);
            else
                printf("%lld is not the sum of two primes!\n",n);
            continue;
        }
        j=lower_bound(prime.begin(),prime.end(),n/2)-prime.begin();
        //cout<<j<<endl;
        for(i=j-1;i>=0;i--)
        {
            a=prime[i];
            b=n-a;
            if(isPrime[b])
            {
                printf("%lld is the sum of %lld and %lld.\n",n,a,b);
                break;
            }
        }
        if(i<0)
            printf("%lld is not the sum of two primes!\n",n);
    }
    return 0;
}


