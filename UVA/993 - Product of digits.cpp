#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m,i,j,ans,t;
    scanf("%lld",&t);
    while(t--)
    {
        ans=0;
        j=0;
        scanf("%lld",&n);
        if(n<=1)
        {
            printf("%lld\n",n);
            continue;
        }
        for(i=9;i>1;i--)
        {
            while(n%i==0)
            {
                ans+=ceil((i*pow(10,j)));
                n=n/i;
                j++;
            }
        }
        if(n>1)
            ans=-1;
        printf("%lld\n",ans);
    }

    return 0;
}

