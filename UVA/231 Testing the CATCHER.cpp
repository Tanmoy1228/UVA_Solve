#include<bits/stdc++.h>
using namespace std;
int dp[32800],l;
vector<int>v;
int longest(int a)
{
    if(dp[a]!=-1)
    {
        return dp[a];
    }
    int m=0,j,k;
    for(j=a;j<l;j++)
    {
        if(v[a]<v[j])
        {
            k=longest(j);
            if(k>m)
                m=k;
        }
    }
    dp[a]=1+m;
    return dp[a];
}

int main()
{
    int t=0,n,i,lis,x,y,bl=0;
    while(scanf("%d",&n))
    {
        if(n==-1)
            break;
        memset(dp,-1,sizeof(dp));
        t++;
        v.push_back(n);
        while(1)
        {
            scanf("%d",&n);
            if(n==-1)
            {
                break;
            }
            v.push_back(n);
        }
        if(bl>0)
            printf("\n");
        bl++;
        reverse(v.begin(),v.end());
        l=v.size();
        lis=0;
        for(i=0;i<l;i++)
        {
            x=v[i];
            y=longest(i);
            if(y>lis)
            {
                lis=y;
            }
        }
        printf("Test #%d:\n  maximum possible interceptions: %d\n",t,lis);
        v.clear();
    }
    return 0;
}
