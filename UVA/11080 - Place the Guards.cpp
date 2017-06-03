#include<bits/stdc++.h>
using namespace std;
vector<long long int>graph[209];
bool visit[209];
long long int color[209];
long long int total,c;

void dfs(long long int u)
{
    visit[u]=true;
    //cout<<u<<endl;
    long long int v,i;
    for(i=0; i<graph[u].size(); i++)
    {
        v=graph[u][i];
        if(!visit[v])
        {
            if(color[u]==c)
                color[v]=c+1;
            else if(color[u]==c+1)
                color[v]=c;
            dfs(v);
        }
        else if(color[u]==color[v] && color[u]!=0)
        {
            total=-100000;
            //cout<<u<<" "<<v<<endl;
            //cout<<color[u]<<" "<<color[v]<<endl;
        }
    }
}

int main()
{
    long long int node,t=1,T,edge;
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld %lld",&node,&edge);
        long long int i,j,u,v,k,one,two;
        for(i=0; i<node; i++)
            graph[i].clear();
        memset(visit,false,sizeof visit);
        memset(color,0,sizeof color);
        for(i=0; i<edge; i++)
        {
            scanf("%lld %lld",&u,&v);

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        total=0;
        for(i=0; i<node; i++)
        {
            c=2*i+1;
            //color[i]=c;
            one=0;
            two=0;
            long long int z;
            z=1;
            if(!visit[i])
            {
                color[i]=c;
                dfs(i);
                for(j=0; j<node; j++)
                {
                    if(color[j]==c)
                        one++;
                    else if(color[j]==c+1)
                        two++;
                }
                total+=max(z,min(one,two));
            }
        }
//        for(j=0; j<node; j++)
//        {
//            cout<<color[j]<<" ";
//        }
//        cout<<endl;
        if(total>0)
            printf("%lld\n",total);
        else
            printf("-1\n");
    }
    return 0;
}
