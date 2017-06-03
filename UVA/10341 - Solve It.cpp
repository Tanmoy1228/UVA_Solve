#include <bits/stdc++.h>
#define ll long long int
#define eps 1e-8

using namespace std;

double p,q,r,s,t,u;

double check(double x)
{
    double ans;
    ans = p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
    return ans;
}

double binary()
{
    ll i;
    double low,high,mid,ans;

    low=0;
    high=1;
    ans=0;
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
    while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)!=EOF)
    {
        double ans=check(0.0)*check(1.0);
        if(ans>0)
            printf("No solution\n");
        else
        {
            double ans=binary();
            printf("%0.4lf\n",ans);
        }
    }
    return 0;
}

