#include<bits/stdc++.h>
using namespace std;
vector<long long int>graph[100009],ans[100009];
bool visit[100009];
long long int dis[100009],bak[100009];
long long int counter,total;

void bfs(long long int u, long long int par)
{
    dis[u]=counter;
    bak[u]=counter;
    counter++;
    visit[u]=true;
    long long int v,i;
    for(i=0;i<graph[u].size();i++)
    {
        v=graph[u][i];
        if(v==par)
            continue;
        if(!visit[v])
        {
            bfs(v,u);
            bak[u]=min(bak[u],bak[v]);
            if(bak[v]>dis[u])
            {
                if(v>u)
                    ans[u].push_back(v);
                else
                    ans[v].push_back(u);
                total++;
            }
        }
        else
        {
            bak[u]=min(bak[u],dis[v]);
        }
    }
}

int main()
{
    long long int node,t=1;
    while(scanf("%lld",&node)!=EOF)
    {
        long long int i,j,u,v,k;
//        if(t>1)
//
//        t++;
        for(i=0;i<node;i++)
        {
            graph[i].clear();
            ans[i].clear();
            visit[i]=false;
        }
        for(i=0;i<node;i++)
        {
            scanf("%lld (%lld)",&u,&k);

            for(j=1;j<=k;j++)
            {
                scanf("%lld",&v);
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
            sort(graph[u].begin(),graph[u].begin()+graph[u].size());
        }
        counter=0;
        total=0;
        for(i=0;i<node;i++)
        {
            if(!visit[i])
                bfs(i,i);
        }
        printf("%lld critical links\n",total);
        for(i=0;i<node;i++)
        {
            if(ans[i].size()>0)
            {
                sort(ans[i].begin(),ans[i].begin()+ans[i].size());
                for(j=0;j<ans[i].size();j++)
                {
                    printf("%lld - %lld\n",i,ans[i][j]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
