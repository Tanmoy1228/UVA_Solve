#include<bits/stdc++.h>
using namespace std;

bool visit[20005];
int colour[20005];
vector<int>v1[20005],v2;

void dfs(int u)
{
    int v,i,l;
    visit[u]=true;
    l=v1[u].size();
    for(i=0; i<l; i++)
    {
        v=v1[u][i];
        if(!visit[v])
        {
            if(colour[u]==1)
                colour[v]=2;
            else if(colour[u]==2)
                colour[v]=1;
            dfs(v);
        }
    }
}
int main()
{
    int t;
    int bull,cow,field,i,j,u,v,m,m1,m2,x,y;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&bull,&cow,&field);
        for(i=1; i<=cow+bull; i++)
        {
            v1[i].clear();
            visit[i]=false;
            colour[i]=-1;
        }
        m1=max(cow,bull);
        m2=min(cow,bull);
        for(i=1; i<=field; i++)
        {
            scanf("%d %d",&u,&v);
            v1[u].push_back(v);
            v1[v].push_back(u);
        }
        for(i=1; i<=cow+bull; i++)
        {
            m=max(m1,m2);
            m2=m1+m2-m;
            m1=m;
            if(!visit[i])
            {
                memset(colour,-1,sizeof colour);
                colour[i]=1;
                x=0;
                y=0;
                dfs(i);
                for(j=i; j<=cow+bull; j++)
                {
                    if(colour[j]==1)
                        x++;
                    else if(colour[j]==2)
                        y++;
                }
                m1-=max(x,y);
                m2-=min(x,y);
                //cout<<m1<<" "<<m2<<endl;
            }
        }
        if(m1>0 || m2>0)
            cout<<"no\n";
        else
            cout<<"yes\n";
    }
    return 0;
}
