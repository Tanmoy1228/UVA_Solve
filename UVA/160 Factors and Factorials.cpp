#include<bits/stdc++.h>
#define ll long long int
#define MAX 10000009
using namespace std;

bool isPrime[MAX+5];

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

void No_Of_Trailing_Zeroes_In_N_Fact_In_Base_B(ll N)
{
    ///We can break the Base B as a product of primes :
    /// B = a^p1 * b^p2 * c^p3 * ...
    ///Then the number of trailing zeroes in N factorial in Base B is given by the formulae
    ///min{1/p1(n/a + n/(a*a) + ….), 1/p2(n/b + n/(b*b) + ..), ….}.

    ll i,j,num,ans,total;
    ans=pow(10,10);
    num=0;
    for(i=2; i<=N; i++)
    {
        if(isPrime[i])
        {
            j=1;
            total=0;
            if(num==15)
                printf("\n      ");
            while( floor(N / ceil( pow(i,j) ))> 0 )
            {
                total += N / ceil( pow(i,j) ); ///No. of total i in N!
                j++;
            }
            printf("%3lld",total);
            num++;
        }
    }
}


int main()
{
    ll n,m,i,j,ans;
    seive_N_logN(100);
    while(scanf("%lld",&n) && n)
    {
        ans=0;
        printf("%3lld! =",n);
        No_Of_Trailing_Zeroes_In_N_Fact_In_Base_B(n);
        printf("\n");
    }

    return 0;
}

