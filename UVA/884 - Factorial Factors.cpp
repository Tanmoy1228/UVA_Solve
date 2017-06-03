#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool isPrime[1000000+5];
ll A[1000005];

void seive_N_logN(ll N)
{
    //calculate prime upto N in NlogN time
    memset(isPrime,true,sizeof isPrime);

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
}


void func(ll N)
{
    ll  n,m,i,j,ans;
    n=N;
    ans=0;
    memset(A,0,sizeof A);
    for(i=2; i<=N; i++)
    {
        n=i;

        for(j=2;j*j<=n;j++)
        {
            if(n%j==0)
            {
                while(n%j==0)
                {
                    n=n/j;
                    ans++;
                }
            }
        }
        if(n!=1)
            ans++;

        A[i]=ans;
    }
}


int main()
{
    ll n,b,m,i,j,ans;
    seive_N_logN(1000003);
    func(1000003);
    //freopen("in.txt","r",stdin);

    while(scanf("%lld",&n)!=EOF)
    {
        ans=A[n];
        //cout<<ans<<endl;
        printf("%lld\n",ans);
        //cout<<ans1<<" "<<ans2<<endl;
    }

    return 0;
}




