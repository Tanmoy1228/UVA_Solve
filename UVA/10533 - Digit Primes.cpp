#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000009
using namespace std;

ll digitprime[MAX+5];
bool isPrime[MAX+5];

void seive_N_logN(ll N)
{
    ///calculate prime upto N in NlogN time
    memset(isPrime,true,sizeof isPrime);
    //prime.clear();

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
//    for(ll i=1; i<MAX; i++)
//        if(isPrime[i])
//            prime.push_back(i);
}

ll calsum(ll n)
{
    ll a,sum=0;
    while(n>0)
    {
        a=n%10;
        sum+=a;
        n=n/10;
    }
    return sum;
}

void primedigit(ll n)
{
    ll i,m;
    for(i=1;i<=n;i++)
    {
        m=calsum(i);
        if(isPrime[m] && isPrime[i])
            digitprime[i]=digitprime[i-1]+1;
        else
            digitprime[i]=digitprime[i-1];
    }
}


int main()
{
    ll n,m,i,j,ans,t;
    seive_N_logN(MAX);
    primedigit(MAX);
    scanf("%lld",&t);
    while(t--)
    {
        ans=0;
        scanf("%lld %lld",&n,&m);
        ans=digitprime[m]-digitprime[n-1];
        printf("%lld\n",ans);
    }

    return 0;
}

