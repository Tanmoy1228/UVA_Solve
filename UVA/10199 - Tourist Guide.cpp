#include<bits/stdc++.h>
using namespace std;
bool visit[109],artpoint[109];
vector<int>graph[109],ans;
int counter,total,srcpoint,src,dis[109],bak[109];
void bfs(int u)
{
    dis[u]=counter;
    bak[u]=counter;
    counter++;
    visit[u]=true;
    for(int i=0; i<graph[u].size(); i++)
    {
        int v;
        v=graph[u][i];
        if(!visit[v])
        {
            bfs(v);
            bak[u]=min(bak[u],bak[v]);
            if(u==srcpoint)
            {
                src++;
            }
            if(u==srcpoint && src>=2 && !artpoint[u])
            {
                artpoint[u]=true;
                ans.push_back(u);
                total++;
                //cout<<u<<"  "<<v<<endl;
            }
            if(dis[u]<=bak[v] && !artpoint[u] && u!=srcpoint)
            {
                artpoint[u]=true;
                ans.push_back(u);
                total++;
                //cout<<u<<"  "<<v<<endl;
            }
        }
        else
            bak[u]=min(bak[u],dis[v]);
    }
}
int main()
{
    int n,i,j,road,t=1;
    char city[100],city1[100],city2[100];
    map<string,int>m1;
    map<int,string>m2;
    vector<string>ans1;
    while(scanf("%d",&n) && n)
    {
        getchar();
        m1.clear();
        m2.clear();
        for(i=1; i<=n; i++)
        {
            gets(city);
            m1[city]=i;
            m2[i]=city;
        }
        for(i=0; i<=n; i++)
        {
            graph[i].clear();
            visit[i]=false;
            artpoint[i]=false;
        }
        scanf("%d",&road);
        for(i=1; i<=road; i++)
        {
            scanf("%s %s",city1,city2);
            graph[m1[city1]].push_back(m1[city2]);
            graph[m1[city2]].push_back(m1[city1]);
        }
        if(t!=1)
            printf("\n");
        counter=1;
        total=0;
        src=0;
        srcpoint=1;
        ans.clear();
        for(i=1; i<=n; i++)
        {
            if(!visit[i])
            {
                srcpoint=i;
                counter=1;
                src=0;
                bfs(srcpoint);
            }
        }

        printf("City map #%d: %d camera(s) found\n",t,total);
        ans1.clear();
        for(i=0; i<ans.size(); i++)
        {
            ans1.push_back(m2[ans[i]]);
            //cout<<m2[ans[i]]<<endl;
//            city=m2[ans[i]];
//            printf("%s\n",city);
        }
        sort(ans1.begin(),ans1.begin()+ans1.size());
        for(i=0; i<ans1.size(); i++)
        {
            cout<<ans1[i]<<endl;
//            city=m2[ans[i]];
//            printf("%s\n",city);
        }
//        for(i=1; i<=n; i++)
//        {
//            cout<<bak[i]<<"  "<<dis[i]<<endl;
//        }

        t++;
    }
    return 0;
}
