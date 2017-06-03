#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll parrent[1000],mark,channel,outpost;
vector<double>v1;

struct data
{
    ll u,v;
    double w;
    bool operator < (const data& p) const
    {
        return w<p.w;
    }
};
ll find_parrent(ll n)
{
    if(parrent[n]==n)
        return n;
    else
        return parrent[n]=find_parrent(parrent[n]);
}
vector<data>v;

double mst()
{
    ll x,y,i;
    data D;
    double mincost=0;
    ll takenedge=0;
    for(i=0; i<=outpost; i++)
        parrent[i]=i;
    for(i=0; i<v.size(); i++)
    {
        D=v[i];
        x=find_parrent(D.u);
        y=find_parrent(D.v);
        if(x==y)
            continue;
        else
        {
            parrent[x]=parrent[y];
            takenedge++;
            v1.push_back(D.w);
        }
        if(takenedge==outpost-1)
        {
            mark=1;
            break;
        }
    }
    return mincost;
}


int main()
{
    ll t,n,m,i,j,X[1000],Y[1000];
    data D;
    double ans;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&channel,&outpost);
        v.clear();
        v1.clear();

        for(i=1; i<=outpost; i++)
        {
            scanf("%lld %lld",&X[i],&Y[i]);
        }

        for(i=1; i<=outpost; i++)
        {
            for(j=1; j<=outpost; j++)
            {
                if(i==j)
                    continue;
                D.u=i;
                D.v=j;
                D.w= sqrt( pow(X[i]-X[j],2.0) + pow(Y[i]-Y[j],2.0) );
                v.push_back(D);
            }
        }
        sort(v.begin(),v.end());
        mark=1;
        ans=mst();
        sort(v1.begin(),v1.end());
        reverse(v1.begin(),v1.end());

        printf("%0.2lf\n",v1[channel-1]);
    }

    return 0;
}

