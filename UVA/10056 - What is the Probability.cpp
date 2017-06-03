#include<bits/stdc++.h>
#define ll long long int
#define esp 1e-9
using namespace std;

int main()
{
    ll t,T,n,m,i,j,man;
    double pro,p,ans;
    scanf("%lld",&T);
    //while(scanf("%lld",&n)!=EOF)
    for(t=1;t<=T;t++)
    {
        scanf("%lld %lf %lld",&n,&p,&m);
        man=m;
        pro=1.0;
        ans=0.00;

        while(pro>esp)
        {
            pro=p*powl((1.0-p),(man-1));
            ans+=pro;
            man+=n;
        }
        printf("%0.4lf\n",ans);
    }
    return 0;
}

