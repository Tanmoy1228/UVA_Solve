#include<bits/stdc++.h>
using namespace std;
int counter,root,src,total,n,takesource;
vector<int>graph[111];
int visit[111],baak[111],dis[111],art[111];
void artpoint(int u)
{
    visit[u]=1;
    int i,v;
    counter++;
    dis[u]=counter;
    baak[u]=counter;
    for(i=0; i<graph[u].size(); i++)
    {
        v=graph[u][i];
        if(!visit[v])
        {
            artpoint(v);
            if(u==src)
            {
                root++;
            }
            if(root>1 && takesource!=1)
            {
                total++;
                takesource=1;
            }
            baak[u]=min(baak[u],baak[v]);
            if(baak[v]>=dis[u] && u!=src && art[u]!=1)
            {
                total++;
                art[u]=1;
            }
        }
        else
        {
            baak[u]=min(baak[u],dis[v]);
        }
    }
}
int main()
{
    int i,j,k,length;
    char s[500];
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
        getchar();
        while(1)
        {
            gets(s);
            length=strlen(s);
            if(s[0]-'0'==0)
            {
                break;
            }
            int a=0,index,init=1;
            for(i=0; i<length; i++)
            {
                if(s[i]==' ')
                {
                    if(init==1)
                    {
                        index=a;
                    }
                    else
                    {
                        graph[index].push_back(a);
                        graph[a].push_back(index);
                    }
                    a=0;
                    init++;
                    continue;
                }
                k=s[i]-'0';
                a=a*10;
                a=a+k;
            }
            graph[index].push_back(a);
            graph[a].push_back(index);
        }
        for(i=1; i<=n; i++)
        {
            sort(graph[i].begin(),graph[i].begin()+graph[i].size());
        }
        src=1;
        counter=0;
        total=0;
        root=0;
        takesource=0;
        artpoint(src);
        cout<<total<<endl;
        for(i=0; i<=n+5; i++)
        {
            graph[i].clear();
            visit[i]=0;
            baak[i]=0;
            dis[i]=0;
            art[i]=0;
        }
//        for(i=1; i<=n; i++)
//        {
//            cout<<i<<"-->";
//            for(j=0; j<graph[i].size(); j++)
//            {
//                cout<<graph[i][j]<<"  ";
//            }
//            cout<<endl;
//        }
    }
    return 0;
}
