#include<bits/stdc++.h>
using namespace std;
vector<long long int> graph[109];
long long int n,cost[109][109],flow,lst,fst,parrent[109];
bool visit[109];

bool bfs(long long int u)
{
    long long int v,i;
    //cout<<u<<endl;
    visit[u]=true;
    if(u==lst)
        return true;
    for(i=0;i<graph[u].size();i++)
    {
        v=graph[u][i];
        //cout<<v<<endl;
        if(!visit[v] && cost[u][v]>0)
        {
            flow=min(flow,cost[u][v]);
            parrent[v]=u;
            bfs(v);
        }
    }
    return visit[lst];
}
int main()
{
    long long int t=1,T,m,i,j,c,u,v,w,total;
    bool take[109][109];
    //scanf("%lld",&T);
    //for(t=1;t<=T;t++)
    while(scanf("%lld",&n) && n)
    {
        //scanf("%lld",&n);
        scanf("%lld %lld %lld",&fst,&lst,&m);
        for(i=1;i<=n+2;i++)
            graph[i].clear();
        memset(cost,0,sizeof cost);
        memset(take,false,sizeof take);
        for(i=1;i<=m;i++)
        {
            scanf("%lld %lld %lld",&u,&v,&w);
            if(!take[u][v])
            {
                take[u][v]=take[v][u]=true;
                graph[u].push_back(v);
                graph[v].push_back(u);
                cost[u][v]=w;
                cost[v][u]=w;
            }
            else
            {
                cost[u][v]+=w;
                cost[v][u]+=w;
            }
        }

        total=0;
        flow=999999999;
        memset(visit,false,sizeof visit);
        memset(parrent,-1,sizeof parrent);
        while(bfs(fst))
        {
            //cout<<flow<<endl;
            for(v=lst;v!=fst;v=parrent[v])
            {
                //cout<<v<<endl;
                u=parrent[v];
                cost[u][v]-=flow;
                cost[v][u]+=flow;
            }
            total+=flow;
            flow=999999999;
            memset(visit,false,sizeof visit);
            memset(parrent,-1,sizeof parrent);
        }
        cout<<"Network "<<t++<<endl;
        cout<<"The bandwidth is ";
        cout<<total<<"."<<endl<<endl;

    }
    return 0;
}

