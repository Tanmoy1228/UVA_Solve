#include<bits/stdc++.h>
long long int arr[]= {1,5,10,25,50};
long long int dp[6][7490],n,m;
long long int call(long long int i, long long int make)
{
    long long int ret1=0,ret2=0;
    if(make==0)
        return 1;
    if(i>4)
        return 0;
    if(dp[i][make]!=-1)
        return dp[i][make];
    if(make-arr[i]>=0)
        ret1=call(i,make-arr[i]);
    ret2=call(i+1,make);
    return dp[i][make]=ret1+ret2;
}
int main()
{
    long long int l,x,y;
    memset(dp,-1,sizeof dp);
    call(0,7489);
    while(scanf("%lld",&n)!=EOF)
    {
        l=call(0,n);
        printf("%lld\n",l);
    }
    return 0;
}
