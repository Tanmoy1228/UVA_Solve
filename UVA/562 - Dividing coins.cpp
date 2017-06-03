#include<bits/stdc++.h>
using namespace std;
int coin[102],dp[101][50000];
int n,total=0;

int call(int i,int cost)
{
    int r1=0,r2=0,r3=0;

    if(i>n)
        return 0;

    else if(cost-coin[i]==0)
        return dp[i][cost]=cost;

    else if(dp[i][cost]!=-1)
        return dp[i][cost];

    if(cost-coin[i]>0)
    {
        r1=coin[i]+call(i+1,cost-coin[i]);
        //cout<<i<<" "<<cost<<" "<<r1<<endl;
    }
    r2=call(i+1,cost);
    r3 = max(r1,r2);
    //cout<<i<<" "<<cost<<" "<<r3<<endl;
    return dp[i][cost]=r3;
}
int main()
{
    int t,b,i,mid;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        total=0;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&coin[i]);
            total=total+coin[i];
        }
        mid=total/2;
        b=call(1,mid);
        printf("%d\n",total-2*b);
    }
    return 0;
}
