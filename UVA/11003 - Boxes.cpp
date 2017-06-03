#include<bits/stdc++.h>
using namespace std;
long long int n,maxi,weight[1009],load[1009],dp[1009][6200];
long long int knapsak(long long int i,long long int l)
{
    //cout<<l<<endl;
    if(i>n)
        return 0;
    if(l<0)
        return 0;
    if(dp[i][l]!=-1)
        return dp[i][l];
    long long int r1=0,r2=0;
    if(weight[i]<=l)
        r1=1+knapsak(i+1,min(l-weight[i],load[i]));
    r2=knapsak(i+1,l);
    //cout<<i<<" "<<r1<<" "<<r2<<endl;
    return dp[i][l]=max(r1,r2);
}
int main()
{
    long long int a,i;
    while(scanf("%lld",&n)==1 && n)
    {
        memset(dp,-1,sizeof dp);
        maxi=0;
        for(i=1; i<=n; i++)
        {
            scanf("%lld %lld",&weight[i],&load[i]);
        }
        a=knapsak(1,6100);
        printf("%lld\n",a);
    }
    return 0;
}
