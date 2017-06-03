#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

struct data
{
    int u,v,w;
    bool operator < (const data& p) const
    {
        return w<p.w;
    }
};
vector<int>taken;
vector<data>v;
map<int,int>m;
long long int parrent[109];
long long int t,T,city,road,city1,city2,cost,mstcost,i,counter,mark,used_edge,totalcost;

long long int find_parrent(long long int node)
{
    if(parrent[node]==node)
        return node;
    else
        return parrent[node]=find_parrent(parrent[node]);
}

void find_mst()
{
    long long int x,y,k;
    used_edge=0;
    mark=0;
    for(i=1; i<=city; i++)
    {
        parrent[i]=i;
    }
//    for(i=1; i<=road; i++)
//    {
//        cout<<v[i-1].u<<"  "<<v[i-1].v<<"  "<<v[i-1].w<<endl;
//    }
    data D;
    for(i=0; i<road; i++)
    {
        D=v[i];
        x=find_parrent(D.u);
        y=find_parrent(D.v);
        //cout<<D.u<<"  "<<D.v<<"  "<<x<<"  "<<y<<"  "<<mstcost<<endl;
        if(x==y)
            continue;
        else
        {
            parrent[x]=parrent[y];
            taken.push_back(i);
            mstcost = mstcost+D.w;
            used_edge++;
        }
        if(used_edge==city-1)
        {
            mark=1;
            //cout<<mstcost<<endl;
            break;
        }

    }
}
void second_mst()
{
    long long int k,x,y;
    totalcost=99999999;

    data D;
    for(k=0; k<city-1; k++)
    {
        for(i=1; i<=city; i++)
        {
            parrent[i]=i;
        }
        mstcost=0;
        used_edge=0;
        for(i=0; i<road; i++)
        {
            if(i==taken[k])
                continue;
            D=v[i];
            x=find_parrent(D.u);
            y=find_parrent(D.v);
            //cout<<D.u<<"  "<<D.v<<"  "<<x<<"  "<<y<<"  "<<mstcost<<endl;
            if(x==y)
                continue;
            else
            {
                parrent[x]=parrent[y];
                mstcost = mstcost+D.w;
                used_edge++;
            }
            if(mstcost > totalcost)
                break;
            if(used_edge==city-1)
            {
                totalcost=mstcost;
                break;
            }
        }
    }
}
int main()
{
    data D;
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld %lld",&city,&road);
        counter=1;
        m.clear();
        taken.clear();
        v.clear();
        for(i=0; i<road; i++)
        {
            scanf("%lld %lld %lld",&city1,&city2,&cost);

            if(m.find(city1)==m.end())
            {
                m[city1]=counter;
                counter++;
            }
            if(m.find(city2)==m.end())
            {
                m[city2]=counter;
                counter++;
            }
            D.u=m[city1];
            D.v=m[city2];
            D.w=cost;
            v.push_back(D);
        }
        if(city==1)
        {
            printf("Case #%lld : No second way\n",t);
            continue;
        }

        sort(v.begin(),v.begin()+road);
        mstcost=0;
        find_mst();

        if(city-1==road && mark==1)
        {
            printf("Case #%lld : No second way\n",t);
        }
        else if(mark==1)
        {
            second_mst();
            printf("Case #%lld : %lld\n",t,totalcost);
            //cout<<totalcost<<endl;
        }
        else
            printf("Case #%lld : No way\n",t);
        //cout<<"ok\n";
    }
    return 0;
}
