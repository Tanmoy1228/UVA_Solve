#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool isPrime[1000000+5];

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


ll func(ll N, ll M)
{
    ll  n,m,i,j,num1,num2,ans,total1,total2;
    n=N;
    m=M;
    for(i=2; i*i<=max(n,m); i++)
    {
        total1=0;
        total2=0;

        if(isPrime[i])
        {
            j=1;
            while( floor(n / ceil( pow(i,j) ))> 0 )
            {
                total1 += n / ceil( pow(i,j) );
                j++;
            }

            if(M%i==0)
            {
                while(M%i==0)
                {
                    total2 ++;
                    M=M/i;
                }
            }
        }
        if(total1 < total2)
        {
            //cout<<total1<<" "<<total2<<" "<<i<<endl;
            return -1;
        }
    }
    if(M > n)
    {
        return -1;
    }

    return 0;
}


int main()
{
    ll n,b,m,i,j,ans1,ans2;
    seive_N_logN(1000000);
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        if(n==0 || m==0)
        {
            if(n==0 && m==1)
                printf("%lld divides %lld!\n",m,n);
            else if(m==0)
                printf("%lld does not divide %lld!\n",m,n);
            else
                printf("%lld does not divide %lld!\n",m,n);
            continue;
        }
        ans1=func(n,m);
        if(ans1==-1)
            printf("%lld does not divide %lld!\n",m,n);
        else
            printf("%lld divides %lld!\n",m,n);
        //cout<<ans1<<" "<<ans2<<endl;
    }

    return 0;
}


