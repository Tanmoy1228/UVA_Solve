#include <bits/stdc++.h>
#define ll long long int
#define eps 1e-8

using namespace std;

ll T;
double cf[20];

double check(double x)
{
    double ans;
    ans=cf[0];
    for(ll i=1; i<=T; i++)
        ans+=(cf[i]/(powl(1+x,i)));
    return ans;
}

double binary()
{
    ll i;
    double low,high,mid,ans;

    low=-1.00;
    high=pow(10,7);
    ans=-1.00;
    while(low+eps<high)
    {
        mid=(low+high)/2;
        if(check(mid)*check(low)<=0)
            high=mid;
        else
            low=mid;
    }
    return mid;
}

int main()
{
    ll n,m,i,d;
    while(scanf("%lld",&T) && T)
    {
        for(i=0; i<=T; i++)
        {
            scanf("%lf",&cf[i]);
        }
        if(check(-0.99)*check(1000000)>0)
        {
            printf("No\n");
            continue;
        }
        double ans=binary();
        printf("%0.2lf\n",ans);
    }
    return 0;
}


