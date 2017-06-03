#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

struct data
{
    int a;
    bool operator < (data const& p) const
    {
        return a>p.a;
    }
};

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,k,l=0,x=0;
        int a[4000]={0};
        data d;
        priority_queue<data>q;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(n==1)
        {
            cout<<"Jolly\n";
            continue;
        }
        for(i=1;i<n;i++)
        {
            k=fabs(a[i]-a[i+1]);
            d.a=k;
            q.push(d);
            if(k>=n)
            {
                cout<<"Not jolly\n";
                x=1;
                break;
            }
        }
        if(x==1)
        {
            continue;
        }
        l=q.size();
        j=1;
        for(i=0;i<l;i++)
        {
            d=q.top();
            k=d.a;
            q.pop();
            //cout<<k<<endl;
            if(k!=j)
            {
                cout<<"Not jolly\n";
                x=2;
                break;
            }
            j++;
        }
        if(x!=2)
        {
            cout<<"Jolly\n";
        }
    }
    return 0;
}
