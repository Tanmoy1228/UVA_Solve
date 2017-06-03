#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector < pair < ll, ll> > v[105];
ll u,A[105];
bool visit[105];
pair<ll , ll> dp[105],k;
void dfs(ll x)
{
    ll y,i;
    //cout<<A[x]<<"  ";
    if(dp[x].first!=-1)
        return;
    visit[x]=true;
    if(v[x].size()==0)
    {
        u=x;
        dp[x].first=A[x];
        dp[x].second=x;
        return;
    }
    y=v[x][0].second;
//    if(visit[y])
//        return;
    dfs(y);
    dp[x].first=A[x]+dp[y].first;
    dp[x].second=dp[y].second;
    return;
}
int main()
{
    ll t,T,n,m,i,j,a,b,maxi;

    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld %lld",&n,&m);
        for(i=0; i<n; i++)
        {
            scanf("%lld",&A[i]);
            v[i].clear();
            dp[i].first=-1;
        }
        for(i=1; i<=m; i++)
        {
            scanf("%lld %lld",&a,&b);
            v[a].push_back(make_pair(A[b],b));
        }
        for(i=0; i<n; i++)
        {
            if(v[i].size()==0)
                continue;
            sort(v[i].begin(),v[i].begin()+v[i].size());
            reverse(v[i].begin(),v[i].begin()+v[i].size());
        }
        memset(visit,false,sizeof visit);
        j=v[0][0].second;
        dfs(j);
        maxi=dp[j].first+A[0];
        b=dp[j].second;
        printf("Case %lld: %lld %lld\n",t,maxi,b);
    }
    return 0;
}
