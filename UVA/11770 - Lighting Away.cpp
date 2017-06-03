#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
vector<int>graph[10009];
int visit[10009],take[10009];
int indegree[10009];
vector<int> finish;

int timer;
void dfs1(int u)
{
    take[u]=1;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(!take[v] && !visit[v])
            dfs1(v);

    }
    finish.push_back(u);
}
void dfs(int u)
{
    visit[u]=1;
    indegree[u]=0;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        indegree[v]=0;
        if(!visit[v])
            dfs(v);

    }
}
int main()
{
    int t,T,n,m,n1,n2,i;
    vector<int>::iterator it;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            graph[i].clear();
            indegree[i]=0;
            visit[i]=0;
            take[i]=0;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&n1,&n2);
            graph[n1].push_back(n2);
            indegree[n2]=1;
        }
        int total=0;
        for(i=1;i<=n;i++)
        {
            if(indegree[i]==0)
            {
                total++;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(indegree[j]==0 && !visit[j])
                {
                    visit[j]=1;
                    for(int k=0;k<graph[j].size();k++)
                    {
                        indegree[graph[j][k]]=0;
                    }
                }
            }
        }
        finish.clear();
        for(i=1;i<=n;i++)
            if(!visit[i] && !take[i])
                dfs1(i);
        int j=finish.size();
        for(j=j-1;j>=0;j--)
        {
            i=finish[j];
            if(indegree[i]==1 && !visit[i])
            {
                dfs(i);
                total++;
            }
        }
        printf("Case %d: %d\n",t,total);
    }
    return 0;
}

