#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m,i,j,ans,a,c,num,first;
    double b;
    while(scanf("%lld",&n) && n!=0)
    {
        ans=1;
        first=0;
        ll neg=0;
        if(n<0)
            neg=1;
        n=abs(n);

        for(i=2; i*i<=n; i++)
        {
            if(n%i==0)
            {
                num=0;
                while(n%i==0)
                {
                    n=n/i;
                    num++;
                }
                if(first==0)
                {
                    first=1;
                    ans=num;
                    continue;
                }
                ans=__gcd(ans,num);
            }
        }
        if(n>1)
            ans=1;

        //cout<<ans<<endl;
        if(neg==1 && ans%2==0)
        {
            while(ans%2==0)
                ans=ans/2;
        }
        printf("%lld\n",ans);
    }

    return 0;
}

