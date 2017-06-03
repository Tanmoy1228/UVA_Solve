#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll ans,n,dis[109],start;
vector< ll >graph[109];
bool visit[109];

ll bfs()
{
    queue<ll>q;
    memset(visit,false,sizeof visit);
    ll u,v,i;
    q.push(start);
    memset(dis,0,sizeof dis);
    dis[start]=0;

    while(!q.empty())
    {
        u=q.front();
        q.pop();

        for(i=0; i<graph[u].size(); i++)
        {
            v=graph[u][i];
            if(dis[u]+1>dis[v])
            {
                dis[v]=dis[u]+1;
                visit[v]=true;
                q.push(v);
            }
        }
    }
}

int main()
{
    ll t=1,T,i,m,a,b,ans;
    while(scanf("%lld",&n) && n)
    {
        scanf("%lld",&start);

        for(i=0; i<=n; i++)
            graph[i].clear();

        while(scanf("%lld %lld",&a,&b) && a && b)
        {
            graph[a].push_back(b);
        }
        for(i=0; i<=n; i++)
            if(graph[i].size()>0)
                sort(graph[i].begin(),graph[i].end());
        bfs();
        m=-1;
        ans=0;

        for(i=1; i<=n; i++)
        {
            if(dis[i]>ans)
            {
                ans=dis[i];
                m=i;
            }
        }
        printf("Case %lld: The longest path from %lld has length %lld, finishing at %lld.\n\n",t++,start,dis[m],m);
    }
    return 0;
}

