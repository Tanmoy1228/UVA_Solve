#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000009
#define MOD 1000000007
using namespace std;
ll ans;
vector<ll> prime;
bool isPrime[MAX+5];
map<ll,ll>mp;
map<ll,ll>:: iterator mt;

ll modpow (ll a, ll b, ll c)
{
    ll res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = (res * a) % c;
        }
        a = (a * a) % c;
        b=b/2;
    }
    return res;
}

ll Modular_Multiplicative_Inverse (ll a, ll p)
{
    return modpow (a, p - 2, p); /// a and p is coprime and p is prime
}

void seive_N_logN(ll N)
{
    ///calculate prime upto N in NlogN time
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


ll DNoOfDivisor_logN(ll N)
{
    ll i,m,j,a,b;
    for(i=0; i<prime.size(),prime[i]*prime[i]<=N; i++)
    {
        m=prime[i];
        j=0;
        if(N%m==0)
        {
            while(N%m==0)
            {
                j++;
                N=N/m;
            }
            a=mp[m]+1;
            b=Modular_Multiplicative_Inverse(a,MOD);
            ans=(ans*b)%MOD;
            mp[m]=max((ll) 0,a-j-1);
            b=max((ll) 1,a-j);
            ans=((ans%MOD)*(b%MOD))%MOD;

        }
    }
    m=sqrt(N);
    if(m*m!=N)///If n is not a full squqre number then there is a prime number after sqrt(n)
    {
        a=mp[N]+1;
        b=Modular_Multiplicative_Inverse(a,MOD);
        ans=(ans*b)%MOD;
        mp[N]=max((ll) 0,a-1-1);
        b=max((ll) 1,a-1);
        ans=((ans%MOD)*(b%MOD))%MOD;
    }
    return ans;
}


ll NoOfDivisor_logN(ll N)
{
    ll i,m,j,a,b;
    for(i=0; i<prime.size(),prime[i]*prime[i]<=N; i++)
    {
        m=prime[i];
        j=0;
        if(N%m==0)
        {
            while(N%m==0)
            {
                j++;
                N=N/m;
            }
            a=mp[m]+1;
            b=Modular_Multiplicative_Inverse(a,MOD);
            ans=(ans*b)%MOD;
            mp[m]=a+j-1;
            b=a+j;
            ans=((ans%MOD)*(b%MOD))%MOD;
        }
    }
    m=sqrt(N);
    if(m*m!=N)///If n is not a full squqre number then there is a prime number after sqrt(n)
    {
        a=mp[N]+1;
        b=Modular_Multiplicative_Inverse(a,MOD);
        ans=(ans*b)%MOD;
        mp[N]=a;
        b=a+1;
        ans=((ans%MOD)*(b%MOD))%MOD;
    }
    return ans;
}


int main()
{
    ll n,a,b,t,T,ans1;

    seive_N_logN(MAX);
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld",&n);
        ans=1;
        ans1=0;
        mp.clear();
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&a);
            if(abs(a)==1)
                ans1=max((ll) 1, ans1);
            else if(a<0)
            {
                a=-a;
                ans1=(ans1%MOD + DNoOfDivisor_logN(a)%MOD)%MOD;
            }
            else
            {
                ans1=(ans1%MOD + NoOfDivisor_logN(a)%MOD)%MOD;
            }
        }
        printf("Case %lld: %lld\n",t,ans1);
    }
    return 0;
}

