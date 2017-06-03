#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll par[5009];
ll findpar(ll p)
{
    if(par[p]==p)
        return p;
    else
        return par[p]=findpar(par[p]);
}
int main()
{
    ll R,C,i,j,l,maxi,a,b,ans[5009];
    char name1[100],name2[100];
    map<string,ll>m;
    //freopen("in.txt","r",stdin);
    while(scanf("%lld %lld",&C,&R))
    {
        m.clear();
        if(R==0 && C==0)
            break;
        getchar();
        for(i=1;i<=C;i++)
        {
            scanf("%s",name1);
            m[name1]=i;
            par[i]=i;
        }
        for(i=1;i<=R;i++)
        {
            scanf("%s %s",name1,name2);
            a=findpar(m[name1]);
            b=findpar(m[name2]);
            if(a!=b)
                par[a]=b;
        }
        maxi=0;
        memset(ans,0,sizeof ans);
        for(i=1;i<=C;i++)
        {
            a=findpar(i);
            ans[a]++;
        }
        for(i=1;i<=C;i++)
            maxi=max(maxi,ans[i]);
        printf("%lld\n",maxi);
    }
    return 0;
}
