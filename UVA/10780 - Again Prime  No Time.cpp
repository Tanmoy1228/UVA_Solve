#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool isPrime[100+5];

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
    ll  n,m,i,j,num1,num2,ans,total1,total2,first;
    n=N;
    m=M;
    first=0;
    ans=9999999999;
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
        else  if(total2!=0)
        {
            ll total = total1/total2;

            ans=min(ans,total);
        }
    }
    //cout<<ans<<endl;
    if(M > n)
    {
        return -1;
    }
    else if(M!=1)
    {
        j=1;
        total1=0;
        while( floor(n / ceil( pow(M,j) ))> 0 )
        {
            total1 += n / ceil( pow(M,j) );
            j++;
        }
        ans=min(ans,total1);
    }

    return ans;
}


int main()
{
    ll n,b,m,i,j,ans1,ans2,T,t;
    seive_N_logN(100);
    //freopen("in.txt","r",stdin);
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld %lld",&m,&n);
        ans1=func(n,m);
        //cout<<ans1<<endl;
        if(ans1==-1)
            printf("Case %lld:\nImpossible to divide\n",t);
        else
            printf("Case %lld:\n%lld\n",t,ans1);
        //cout<<ans1<<" "<<ans2<<endl;
    }

    return 0;
}



