#include<bits/stdc++.h>
#define ll long long int
#define MAX 100009
using namespace std;

ll DivisorSum[MAX+5];
ll DivisorNo[MAX+5];

void NoOfDivisor_N_logN(ll N)
{
    ///calculate NoOfDivisor upto N in NlogN time
    memset(DivisorNo,0,sizeof DivisorNo);
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = i; j <= N; j += i)
        {
            DivisorNo[j] += 1;
        }
    }
}

void SumOfDivisor_N_logN(ll N)
{
    ///calculate SumOfDivisor upto N in NlogN time
    memset(DivisorSum,0,sizeof DivisorSum);
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = i; j <= N; j += i)
        {
            DivisorSum[j] += i;
        }
    }
}


int main()
{
    ll t,n,m,i,j,ans1,ans2,a,b,k;

    NoOfDivisor_N_logN(MAX);
    SumOfDivisor_N_logN(MAX);

    scanf("%lld",&t);
    while(t--)
    {
        ans1=0;
        ans2=0;
        scanf("%lld %lld %lld",&a,&b,&k);

        i=ceil((1.0*a)/(k*1.0));
        //cout<<i<<endl;
        for(i=i*k; i<=b; i=i+k)
        {
            ans1+=DivisorNo[i];
            ans2+=DivisorSum[i];
        }
        printf("%lld %lld\n",ans1,ans2);
    }

    return 0;
}

