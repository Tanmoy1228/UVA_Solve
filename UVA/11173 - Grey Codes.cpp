#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll test;
    scanf("%lld",&test);
    while(test--)
    {
        ll n,k,i,j,ans,devide,mark;
        mark=1;
        ans=0;
        scanf("%lld %lld",&n,&k);
        k++;
        for(i=1; i<=n; i++)
        {
            devide=ceil(pow(2,n-i));
            if(k>devide)
            {
                k=k-devide;
                if(mark==1)
                    ans+=ceil(pow(2,n-i));
                mark=2;

            }
            else if(k<=devide)
            {
                if(mark==2)
                    ans+=ceil(pow(2,n-i));
                mark=1;
            }
        }
        printf("%lld\n",ans);

    }
}
