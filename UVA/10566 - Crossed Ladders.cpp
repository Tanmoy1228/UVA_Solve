#include<bits/stdc++.h>
using namespace std;
#define ll long long int
double x,y,c;
double Binary_Search()
{
    double b,e,mid,ans,ox,oy,o,area,oc,s,k,l;
    b=0;
    e=min(x,y);
    for(ll i=1;i<=300;i++)
    {
        mid=(b+e)/2;

        ox=sqrt(x*x-mid*mid);
        oy=sqrt(y*y-mid*mid);
        o=oy/ox;
        k=(o*x)/(1.0+o);
        l=y/(o+1.0);
        s=(k+l+mid)/2;
        area=sqrt(s*(s-mid)*(s-k)*(s-l));
        oc=(2*area)/mid;

        if(oc<c)
            e=mid;
        else
            b=mid;
    }
    return mid;
}
int main()
{
    ll t,T;
    double ans;
    while(cin>>x>>y>>c)
    {
        //scanf("%lf %lf %lf",&x,&y,&c);
        ans=Binary_Search();
        printf("%0.3lf\n",ans);
    }
    return 0;
}

