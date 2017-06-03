#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll par[100009];
ll findpar(ll p)
{
    if(par[p]==p)
        return p;
    else
        return par[p]=findpar(par[p]);
}
int main()
{
    ll n,t,i,j,c,ans[100005];
    char name1[100],name2[100];
    map<string,ll>m;
    //freopen("in.txt","r",stdin);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        getchar();
        m.clear();
        c=1;
        for(i=1;i<=100001;i++){
            par[i]=i;
            ans[i]=1;
        }
        //memset(ans,1,sizeof ans);
        for(i=1; i<=n; i++)
        {
            scanf("%s %s",name1,name2);
            if(m.find(name1)==m.end())
                m[name1]=c++;
            if(m.find(name2)==m.end())
                m[name2]=c++;
            ll a=findpar(m[name1]);
            ll b=findpar(m[name2]);
            if(a!=b)
            ans[a]+=ans[b];
            ans[b]=ans[a];
            par[a]=b;
            printf("%lld\n",ans[a]);
        }
    }
    return 0;
}
