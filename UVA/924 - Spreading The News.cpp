#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
vector<int> graph[2510];
vector<int>v1,v2;

int main()
{
    int Employee,frnd,man,src,T;
    int i,j;
    scanf("%d",&Employee);
    for(i=0; i<Employee; i++)
    {
        scanf("%d",&frnd);
        for(j=0; j<frnd; j++)
        {
            scanf("%d",&man);
            graph[i].push_back(man);
        }
    }
    scanf("%d",&T);

    for(i=0;i<T;i++)
    {
        scanf("%d",&src);
        if(graph[src].size()==0)
        {
            printf("0\n");

            continue;
        }
        queue<int> q;
        q.push(src);
        bool visit[2510]={0};
        int level[2510]={0};
        int maxi=0,day=0,today=0;
        level[src]=0;

        while(!q.empty())
        {
            man=q.front();
            q.pop();
            visit[man]=true;
            //maxi++;
            int length=graph[man].size();
            for(j=0;j<length;j++)
            {
                frnd=graph[man][j];

                if(!visit[frnd])
                {
                    q.push(frnd);
                    level[frnd]=level[man]+1;
                    day=level[frnd];
                    visit[frnd]=true;
                }
            }
        }
        for(j=1;j<=day;j++)
        {
            int M=count(level,level+Employee,j);
            if(maxi<M)
            {
                maxi=M;
                today=j;
            }
        }
        printf("%d %d\n",maxi,today);
    }
    return 0;
}
