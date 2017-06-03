#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

int parent[20000];
int find_parent(int city)//function for parrent finding
{
    if(parent[city]==city)
    {
        return city;
    }
    else
    {
        return parent[city]=find_parent(parent[city]);
    }
}

struct data      //sorting data max to min and keep node and edge in sane data
{
    int city1,city2,cost;
    bool operator < ( const data& p ) const
    {
        return cost < p.cost;
    }
};

int main()
{
    int city,road,test=0,i=0;
    while(scanf("%d %d",&city,&road))
    {
        if(city==0 && road==0)
        {
            break;
        }
        test++;
        for(i=1; i<city+5; i++)//initialize all parrent to zero
        {
            parent[i]=i;
        }
        char city1[100],city2[100];
        int a,b,c,d,e,f,j,k,l,cost,x=1,y;
        long long int min_capacity;
        data D;
        map<string,int>m;
        map<string,int>:: iterator mt;
        vector<int>v[500];
        priority_queue<data> pq;
        for(i=0; i < road; i++)
        {
            scanf("%s %s %d",&city1,&city2,&cost);
            if(m.find(city1)==m.end())//mapping string by integer
            {
                m[city1]=x;
                x++;
            }
            if(m.find(city2)==m.end())
            {
                m[city2]=x;
                x++;
            }
            v[m[city1]].push_back(m[city2]);
            v[m[city2]].push_back(m[city1]);
            D.city1=m[city1];// push node and edge in data stract
            D.city2=m[city2];// push node and edge in data stract
            D.cost=cost;// push node and edge in data stract
            pq.push(D);//push data stract in priority_queue for sorting max to min
//            parent[m[city1]]=m[city1];
//            parent[m[city2]]=m[city2];
        }
        for(mt=m.begin();mt!=m.end();mt++)
        {
            cout<<mt->first<<"  "<<mt->second<<endl;
        }
        scanf("%s %s",&city1,&city2);
        a=m[city1];
        b=m[city2];
        D=pq.top();
        min_capacity=D.cost;
        x=find_parent(a);//finding parrent of input
        y=find_parent(b);//finding parrent of input
        if(parent[x]==parent[y])//if parrent of input is same that means there is a way
        {
            printf("Scenario #%d\n%d tons\n\n",test,min_capacity);
            continue;
        }
        for(j=1; j<=city; j++)
        {

            D=pq.top();//take the max
            pq.pop();
            c=D.city1;//take the node and edge of max value from struct
            d=D.city2;
            cost=D.cost;
            x=find_parent(c);//find the parrent of taking node
            y=find_parent(d);
            if(parent[x]==parent[y])//if there is a way, cannot take it for avoiding cycle
            {
                continue;
            }

            parent[x]=y;//make a way between them
            if(cost<min_capacity)//take the minimum cost of that path
            {
                min_capacity=cost;
            }
            x=find_parent(a);//finding parrent of input
            y=find_parent(b);//finding parrent of input
            if(parent[x]==parent[y])//if parrent of input is same that means there is a way
            {
                printf("Scenario #%d\n%d tons\n\n",test,min_capacity);
                break;
            }
        }
    }
    return 0;
}


