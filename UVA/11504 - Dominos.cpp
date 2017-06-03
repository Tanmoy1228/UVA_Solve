#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>graph[100009],finish;
bool visit[100009],take[100009];
ll indegree[100009],bak[100009],counter;

void dfs1(ll u)
{
    take[u]=true;
    ll j,l,v;
    l=graph[u].size();
    for(j=0; j<l; j++)
    {
        v=graph[u][j];
        if(!take[v])
        {
            dfs1(v);
        }
    }
    //finish.push_back(u);
}


void dfs(ll u)
{
    visit[u]=true;
    indegree[u]=0;
    ll j,l,v;
    l=graph[u].size();
    for(j=0; j<l; j++)
    {
        v=graph[u][j];
        indegree[v]=0;
        if(!visit[v])
        {
            dfs(v);
        }
    }
}


int main()
{
    ll t,T,n,m,x,y,i,j,k;
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld %lld",&n,&m);
        for(i=0; i<=n; i++)
        {
            graph[i].clear();
            visit[i]=false;
            take[i]=false;
            indegree[i]=0;
        }
        for(i=1; i<=m; i++)
        {
            scanf("%lld %lld",&x,&y);
            graph[x].push_back(y);
            indegree[y]=1;
        }
        counter=0;

        finish.clear();
        for(i=1; i<=n; i++)
        {
            if(!take[i])
            {
                dfs1(i);
                finish.push_back(i);
            }
        }
        memset(take,0,sizeof(take));
        j=finish.size();
        j=j-1;
        for(; j>=0; j--)
        {
            i=finish[j];
            if(!take[i])
            {
                dfs1(i);
                counter++;
            }
        }
        printf("%lld\n",counter);
    }
    return 0;
}
