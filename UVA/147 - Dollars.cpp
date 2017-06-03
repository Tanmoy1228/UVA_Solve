#include<bits/stdc++.h>
using namespace std;
long long int a,m,dp[12][30005];
long long int arr[]={5,10,20,50,100,200,500,1000,2000,5000,10000};

long long int coin(long long int i, long long int make)
{
    long long int r1=0,r2=0;
    if(make==0)
        return 1;
    if(i>11)
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
    double n;
    memset(dp,-1,sizeof dp);
    m=coin(1,30005);
    while(scanf("%lf",&n))
    {
        m=n*100+0.5;
        //m=ceil(n*100.0);
        if(m==0)
            break;
        a=coin(1,m);
        printf("%6.2lf%17lld\n",n,a);
    }
    return 0;
}
