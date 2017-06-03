#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll No_Of_Digits_In_N_Fact_In_Base_B(ll N, ll B)
{

    //The number of digits in N factorial is :
    //floor (ln(n!)/ln(B) + 1)

    ll i;
    double ans=0;
    for(i=1; i<=N; i++)
        ans+= (log10(i)/log10(B));
    ans=ans+1;

    return (ll)ans;
}

ll No_Of_Trailing_Zeroes_In_N_Fact_In_Base_B(ll N, ll B)
{
    //We can break the Base B as a product of primes :
    // B = a^p1 * b^p2 * c^p3 * ...
    //Then the number of trailing zeroes in N factorial in Base B is given by the formulae
    //min{1/p1(n/a + n/(a*a) + ….), 1/p2(n/b + n/(b*b) + ..), ….}.

    ll i,j,num,ans,total;
    ans=pow(10,10);
    for(i=2; i*i<=B; i++)
    {
        if(i>10)
            break;
        if(B%i==0)
        {
            num=0;
            while(B%i==0)
            {
                B=B/i;
                num++;
            }
            j=1;
            total=0;
            while( floor(N / ceil( pow(i,j) ))> 0 )
            {
                total += N / ceil( pow(i,j) );
                j++;
            }
            total = total/num;

            ans=min(ans,total);
        }
    }

    if(B>1)//for last prime
    {
        j=1;
        total=0;
        while(N / ceil( pow(B,j) )>0 )
        {
            total += N / ceil( pow(B,j) );
            j++;
        }
    }

    ans=min(ans,total);

    return ans;
}


int main()
{
    ll n,b,m,i,j,ans1,ans2;
    while(scanf("%lld %lld",&n,&b)!=EOF)
    {
        ans1=No_Of_Trailing_Zeroes_In_N_Fact_In_Base_B(n,b);
        ans2=No_Of_Digits_In_N_Fact_In_Base_B(n,b);

        printf("%lld %lld\n",ans1,ans2);
        //cout<<ans1<<" "<<ans2<<endl;
    }

    return 0;
}

