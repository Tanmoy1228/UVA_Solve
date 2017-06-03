#include<iostream>
#include<cstdio>
#include<math.h>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

int p[200];

int find_D(int f)
{
    if(p[f]==f)
    {
        return f;
    }
    else
    {
        return p[f]=find_D(p[f]);
    }
}

struct data
{
    int u,v;
    float w;
    bool operator < (const data& p) const
    {
        return w>p.w;
    }
};

int main()
{
    int T,t,bl=0;
    scanf("%d",&T);

    for(t=1; t<=T; t++)
    {
        int n,i,j,k,l,x=1,y=1,z=1;
        double a,b,c,d,e,f;
        vector<float>v1;
        vector<float>v2;
        map<float,int>m1;
        map<float,int>m2;
        int arr[500][500];
        int visit[1000]={0};
        priority_queue<data> pq;
        data D;
        scanf("%d",&n);
        for(i=1; i<200; i++)
        {
            p[i]=0;
        }
        for(i=0; i<n; i++)
        {
            scanf("%lf %lf",&a,&b);
            v1.push_back(a);
            v2.push_back(b);
            if(m1[a]==0)
            {
                m1[a]=x;
                x++;
            }
            if(m2[b]==0)
            {
                m2[b]=y;
                y++;
            }
            arr[m1[a]][m2[b]]=z;
            z++;
        }
        l=v1.size();
        for(i=0; i<l; i++)
        {
            a=v1[i];
            b=v2[i];
            for(j=i+1; j<l; j++)
            {
                c=v1[j];
                d=v2[j];
                f=sqrt(pow(fabs(a-c),2)+pow(fabs(b-d),2));
                D.u=arr[m1[a]][m2[b]];
                D.v=arr[m1[c]][m2[d]];
                D.w=f;
                pq.push(D);
                p[arr[m1[a]][m2[b]]]=arr[m1[a]][m2[b]];
                p[arr[m1[c]][m2[d]]]=arr[m1[c]][m2[d]];
            }
        }
        e=0.00;
        k=0;
        while(!pq.empty())
        {
            D=pq.top();
            pq.pop();
            x=D.u;
            y=D.v;
            f=D.w;
            i=find_D(x);
            j=find_D(y);
            if(p[i]==p[j])
            {
                continue;
            }
            p[i]=j;
            e=e+f;
            if(k==n-1)
            {
                break;
            }

        }
        printf("%0.2lf\n",e);
        if(t<T)
        {
            printf("\n");
        }
    }
    return 0;
}

