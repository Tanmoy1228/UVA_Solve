#include<bits/stdc++.h>
using namespace std;
vector<int>v[105];
bool visit[105];
void dfs(int x)
{
    int y,i;
    for(i=0;i<v[x].size();i++)
    {
        y=v[x][i];
        if(!visit[y])
        {
            visit[y]=true;
            dfs(y);
        }
    }
}
int main()
{
    int n,m,i,j,a,b;

    while(scanf("%d",&n)==1 && n)
    {
        for(i=0;i<=n;i++)
            v[i].clear();
        for(;;)
        {
            scanf("%d",&a);
            if(a==0)
                break;
            for(;;)
            {
                scanf("%d",&b);
                if(b==0)
                    break;
                v[a].push_back(b);
            }
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            memset(visit,false,sizeof visit);
            scanf("%d",&a);
            dfs(a);
            b=0;
            for(j=1;j<=n;j++)
                if(!visit[j])
                    b++;
            printf("%d",b);
            for(j=1;j<=n;j++)
                if(!visit[j])
                    printf(" %d",j);
            printf("\n");
        }
    }
    return 0;
}
