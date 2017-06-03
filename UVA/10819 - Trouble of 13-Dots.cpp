#include<bits/stdc++.h>
using namespace std;
long long int value[105],favour[105],money,money1,w,n,dp[105][10300];
long long int knapsak(long long int i, long long int m, long long int money1)
{
    long long int r1,r2;
    r1=0;
    r2=0;
    if(i>n)
        return 0;
    if(dp[i][m]!=-1)
        return dp[i][m];
    if(m+value[i]>2000 && money>1800 && m+value[i]<=money+200)
    {
        r1=favour[i]+knapsak(i+1,m+value[i],money+200);
    }
    else if(m+value[i]<=money1)
        r1=favour[i]+knapsak(i+1,m+value[i],money1);
    r2=knapsak(i+1,m,money1);
    //cout<<money1<<" "<<r1<<" "<<r2<<endl;
    return dp[i][m]=max(r1,r2);
}
int main()
{
    long long int i,j;
    while(scanf("%lld %lld",&money,&n)==2)
    {
        memset(dp,-1,sizeof dp);
        for(i=1; i<=n; i++)
        {
            scanf("%lld %lld",&value[i],&favour[i]);
        }
        printf("%lld\n",knapsak(1,0,money));
    }
    return 0;
}
