#include<bits/stdc++.h>
using namespace std;
long long int a,m,dp[6][30005];
long long int arr[]={1,5,10,25,50};

long long int coin(long long int i, long long int make)
{
    long long int r1=0,r2=0;
    if(make==0)
        return 1;
    if(i>5)
        return 0;
    if(dp[i][make]!=-1)
        return dp[i][make];
    if(make-arr[i-1]>=0)
        r1=coin(i,make-arr[i-1]);
    r2=coin(i+1,make);
    return dp[i][make]=r1+r2;
}
int main()
{
    memset(dp,-1,sizeof dp);
    m=coin(1,30005);
    while(scanf("%lld",&m)!=EOF)
    {
        //m=n*100+0.5;
        //m=ceil(n*100.0);
        if(m==0)
            break;
        a=coin(1,m);
        printf("There are %lld ways to produce %lld cents change.\n",a,m);
    }
    return 0;
}

