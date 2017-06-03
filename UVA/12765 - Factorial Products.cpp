#include<bits/stdc++.h>
#define ll long long int
#define MAX 10000009
using namespace std;

bool isPrime[20];
ll ase[15],ase1[15],ase2[15];

void seive_N_logN(ll N)
{
    ///calculate prime upto N in NlogN time
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

void No_Of_Trailing_Zeroes_In_N_Fact_In(ll N)
{
    ///We can break the Base B as a product of primes :
    /// B = a^p1 * b^p2 * c^p3 * ...
    ///Then the number of trailing zeroes in N factorial in Base B is given by the formulae
    ///min{1/p1(n/a + n/(a*a) + ….), 1/p2(n/b + n/(b*b) + ..), ….}.

    ll i,j,num,ans,total;
    ans=pow(10,10);
    for(i=2; i<=N; i++)
    {
        if(isPrime[i])
        {
            j=1;
            total=0;
            while( floor(N / ceil( pow(i,j) ))> 0 )
            {
                total += N / ceil( pow(i,j) ); ///No. of total i in N!
                j++;
            }
            ase[i]+=total;
        }
    }
}

int main()
{
    ll n,m,i,j,ans;
    memset(ase,0,sizeof ase);
    memset(ase2,0,sizeof ase2);
    seive_N_logN(15);
//    for(i=0;i<10;i++)
//        No(i);
//    for(i=0;i<10;i++)
//        cout<<ase[i]<<endl;

    while(scanf("%lld %lld",&n,&m) && n && m)
    {
        ans=0;
        ll a;
        memset(ase,0,sizeof ase);
        for(i=1; i<=n; i++)
        {
            //memset(ase,0,sizeof ase);

            scanf("%lld",&a);
            No_Of_Trailing_Zeroes_In_N_Fact_In(a);

        }
        for(j=0; j<10; j++)
            ase1[j]=ase[j];

        memset(ase,0,sizeof ase);
        for(i=1; i<=m; i++)
        {
            //memset(ase,0,sizeof ase);

            scanf("%lld",&a);
            No_Of_Trailing_Zeroes_In_N_Fact_In(a);
        }
        for(j=0; j<10; j++)
            ase2[j]=ase[j];
        ll ok=0;

        for(i=0; i<10; i++)
        {
            if(ase1[i]!=ase2[i])
            {
                ok=-1;
                //cout<<i<<endl;
            }
        }
        if(ok==-1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }

    return 0;
}

