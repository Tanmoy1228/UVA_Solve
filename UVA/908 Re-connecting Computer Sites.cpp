#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int s=1000010;
int p_1[1000010],p_2[1000010];

struct data
{
    int u,v,w;
    bool operator < (const data& p) const
    {
        return w>p.w;
    }
};

int find_1(int f)
{
    if(p_1[f]==f)
    {
        return f;
    }
    else
    {
        return p_1[f]=find_1(p_1[f]);
    }
}

int find_2(int f)
{
    if(p_2[f]==f)
    {
        return f;
    }
    else
    {
        return p_2[f]=find_2(p_2[f]);
    }
}

int main()
{
    int n,bl=0;
    while(cin>>n)
    {

        int a,b,c,d,e,i,j,k,l,m,x,y,cost_1=0,cost_2=0;
        data D;

        priority_queue<data>pq,q;

        for(i=1; i<s; i++)
        {
            p_1[i]=0;
            p_2[i]=0;
        }

        for(i=1; i<n; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            p_1[a]=a;
            p_1[b]=b;
            p_2[a]=a;
            p_2[b]=b;
            D.u=a;
            D.v=b;
            D.w=c;
            pq.push(D);
            q.push(D);
        }

        cin>>m;
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            p_2[a]=a;
            p_2[b]=b;
            D.u=a;
            D.v=b;
            D.w=c;
            pq.push(D);
        }
        cin>>m;
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            p_1[a]=a;
            p_1[b]=b;
            p_2[a]=a;
            p_2[b]=b;
            D.u=a;
            D.v=b;
            D.w=c;
            pq.push(D);
            q.push(D);
        }
        if(bl!=0)
        {
            printf("\n");
        }
        bl++;
        while(!q.empty())
        {
            D=q.top();
            q.pop();
            a=D.u;
            b=D.v;
            c=D.w;
            x=find_1(a);
            y=find_1(b);
            if(x==y)
            {
                continue;
            }
            p_1[x]=y;

            cost_1 = cost_1 + c;
        }
        while(!pq.empty())
        {
            D=pq.top();
            pq.pop();
            a=D.u;
            b=D.v;
            c=D.w;
            k=find_2(a);
            l=find_2(b);
            if(k==l)
            {
                continue;
            }
            p_2[k]=l;

            cost_2 = cost_2 + c;
        }
        printf("%d\n%d\n",cost_1,cost_2);
    }
    return 0;
}

