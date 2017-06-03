#include<bits/stdc++.h>

using namespace std;
struct data
{
    long long int u,cost;
    bool operator < ( const data& p ) const
    {
        return cost > p.cost;
    }
};
struct edge
{
    long long int u,v,cost;
    bool operator < ( const edge& p ) const
    {
        return cost < p.cost;
    }
};
long long int t,T,start,des,city,road,city1,city2,usercost,cost,i,j,dis[10009],dis1[10009],maxi;

vector<pair<int,int> >graphcost[10009],revgraphcost[10009];

void dijkstra()
{
    priority_queue<data>pq;
    data D;
    D.u=start;
    D.cost=0;
    dis[start]=0;
    pq.push(D);
    while(!pq.empty())
    {
        D=pq.top();
        pq.pop();
        city1=D.u;
        cost=D.cost;
        //cout<<city1<<"  "<<cost<<endl;
        for(i=0;i<graphcost[city1].size();i++)
        {
            city2=graphcost[city1][i].first;
            if(dis[city1]+graphcost[city1][i].second>usercost)
                continue;
            if(dis[city2]>dis[city1]+graphcost[city1][i].second)
            {
                dis[city2]=dis[city1]+graphcost[city1][i].second;
                D.u=city2;
                D.cost=dis[city2];
                pq.push(D);
            }
        }
    }
}

void dijkstra1()
{
    priority_queue<data>pq;
    data D;
    D.u=des;
    D.cost=0;
    dis1[des]=0;
    pq.push(D);
    while(!pq.empty())
    {
        D=pq.top();
        pq.pop();
        city1=D.u;
        cost=D.cost;
        for(i=0;i<revgraphcost[city1].size();i++)
        {
            city2=revgraphcost[city1][i].first;
            if(dis1[city1]+revgraphcost[city1][i].second>usercost)
                continue;
            if(dis1[city2]>dis1[city1]+revgraphcost[city1][i].second)
            {
                dis1[city2]=dis1[city1]+revgraphcost[city1][i].second;
                D.u=city2;
                D.cost=dis1[city2];
                pq.push(D);
            }
        }
    }
}


int main()
{
    scanf("%lld",&T);
    edge E;
    for(t=1;t<=T;t++)
    {
        scanf("%lld %lld %lld %lld %lld",&city,&road,&start,&des,&usercost);

        priority_queue<edge>path;
        for(i=0;i<=city;i++)
        {
            graphcost[i].clear();
            revgraphcost[i].clear();
            dis[i]=999999;
            dis1[i]=999999;
        }
        for(i=0;i<road;i++)
        {
            scanf("%lld %lld %lld",&city1,&city2,&cost);
            E.u=city1;
            E.v=city2;
            E.cost=cost;
            path.push(E);
            graphcost[city1].push_back(make_pair(city2,cost));
            revgraphcost[city2].push_back(make_pair(city1,cost));
        }
        dijkstra();
        dijkstra1();
        maxi=-1;

        while(!path.empty())
        {
            E=path.top();
            path.pop();

            //cout<<dis[E.u]<<"  "<<dis1[E.v]<<"  "<<graphcost[E.u][E.v]<<endl;
            if(usercost>=dis[E.u]+dis1[E.v]+E.cost)
            {
                maxi=E.cost;
                break;
            }
        }
        printf("%lld\n",maxi);
    }
    return 0;
}
