#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int>graph[110];
int dom[110][110];
bool visit[110],take[110];
void dfs(int u)
{
    take[u]=true;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(!take[v])
        {
            dfs(v);
        }
    }
}

void domin(int u)
{
    visit[u]=true;
    int l,v,i;
    l=graph[u].size();
    for(i=0; i<l; i++)
    {
        v=graph[u][i];
        if(!visit[v])
        {
            domin(v);
        }
    }
}
int main()
{
    int t,T,n;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        int i,j,k;
        scanf("%d",&n);
        for(i=0; i<n+2; i++)
        {
            graph[i].clear();
            visit[i]=false;
            for(j=0; j<n+2; j++)
            {
                dom[i][j]=0;
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d",&k);
                if(k==1)
                {
                    graph[i].push_back(j);
                }
            }
        }
        domin(0);
        for(i=0; i<n; i++)
        {
            if(visit[i]==true)
            {
                dom[0][i]=1;
            }
        }
        for(i=1; i<n; i++)
        {
            if(visit[i])
            {
                dom[i][i]=1;
                memset(take,0,sizeof(take));
                take[i]=true;
                dfs(0);
                for(j=0; j<n; j++)
                {
                    if(visit[j] && !take[j])
                    {
                        dom[i][j]=1;
                    }
                }
            }
        }
        printf("Case :%d\n",t);
        for(i=0; i<n; i++)
        {
            printf("+");
            for(j=0; j<2*n-1; j++)
            {
                printf("-");
            }
            printf("+\n");
            printf("|");
            for(j=0; j<n; j++)
                {
                    if(dom[i][j]==1 )
                        printf("Y|");
                    else
                        printf("N|");
                }
                printf("\n");
        }
        printf("+");
        for(j=0; j<2*n-1; j++)
        {
            printf("-");
        }
        printf("+\n");
    }
    return 0;
}
