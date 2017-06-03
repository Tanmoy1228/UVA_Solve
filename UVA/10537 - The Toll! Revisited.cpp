#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sc(a) scanf("%lld",&a)
bool visit[100000];
vector<ll>graph[10000];
ll des,deliver,strt,m,ok;
vector<ll>par,par1;
bool bfs(ll sum)
{
    ll u,v,i,l,dis[1000];
    queue<ll>Q;
    Q.push(strt);
    memset(dis,0,sizeof dis);
    dis[strt]=sum;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(i=0; i<graph[u].size(); i++)
        {
            v=graph[u][i];
            if(v>96)
            {
                if((dis[v]<dis[u]-1) || ((dis[v]==dis[u]-1) && u<par[v]))
                {
                    dis[v]=dis[u]-1;
                    Q.push(v);
                    par[v]=u;
                    //cout<<char(u)<<" "<<char(v)<<endl;
                }
            }
            else
            {
                if(dis[v]<(dis[u]-ceil(dis[u]*0.05)) || (dis[v]==(dis[u]-ceil(dis[u]*0.05)) && u<par[v]))
                if(dis[v]<(dis[u]-ceil(dis[u]*0.05)))
                {
                    dis[v]=dis[u]-ceil(dis[u]*0.05);
                    Q.push(v);
                    par[v]=u;
                    //cout<<char(u)<<" "<<char(v)<<endl;
                }
            }
        }
    }
    if(dis[des]>=deliver)
        return true;
    else
        return false;
}

ll Binary_Search()
{
    ll low,high,mid,ans;
    low=0;
    high=pow(10,10);

    while(low<=high)
    {
        mid=(low+high)/2;
        memset(visit,false,sizeof visit);
        ok=-1;
        if(bfs(mid))
        {
            ans=mid;
            par1=par;
            par.assign(1000,-1);
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}

int main()
{
    ll n,i,j,u,v,ans,t=0;
    char ch1,ch2;
    while(cin>>n)
    {
        if(n==-1)
            break;
        t++;
        par.assign(1000,-1);
        par1.assign(1000,-1);
        for(i=0; i<=200; i++)
            graph[i].clear();
        for(i=0; i<n; i++)
        {
            cin>>ch1>>ch2;
            u=ch1;
            v=ch2;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cin>>m>>ch1>>ch2;
        strt=ch1;
        des=ch2;
        deliver=m;
        ans=Binary_Search();
        printf("Case %lld:\n%lld\n%c",t,ans,strt);
        par.clear();
        u=des;
        par.push_back(u);

        while(u!=strt)
        {
            u=par1[u];
            par.push_back(u);
        }
        reverse(par.begin(),par.end());

        for(i=1;i<par.size();i++)
            printf("-%c",par[i]);
        cout<<endl;
    }
    return 0;
}

