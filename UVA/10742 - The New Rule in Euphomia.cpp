#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000005

bool isPrime[MAX+5];
vector<ll> prime;

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

ll lowbinary(ll a)
{
    ll i,low,high,mid,ans;

    low=0;
    high=prime.size()-1;
    ans=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(prime[mid]<=a)
        {
            low=mid+1;
            ans=mid;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}


int main()
{
    ll n,i,t=1,a,ans;
    seive_N_logN(MAX);
    sort(prime.begin(),prime.end());
    while(scanf("%lld",&n) && n)
    {
        ans=0;
        for(i=0;prime[i]<n;i++)
        {
            a=n-prime[i];
//            cout<<a<<endl;
            a=lowbinary(a)-i;
//            cout<<a<<" "<<prime[i]<<" "<<prime[a]<<endl;

//            while(prime[a]+prime[i]>n)
//                a--;
//            if(prime[i]>prime[a])
//                a++;
            if(a<0)
                continue;
            ans+=a;
            //cout<<ans<<endl;
        }
        printf("Case %lld: %lld\n",t,ans);
        t++;
    }
    return 0;
}
