#include<iostream>
#include<cstdio>
#include<algorithm>
long long int arr[]= {1,5,10,25,50};
long long int dp[6][7490],n,m;
long long int call(long long int i, long long int make)
{
    long long int ret_1=0,ret_2=0;
    if(make==0)
    {
        return 1;
    }
    if(i>4)
    {
        if(make==0)
        {
            return 1;
        }
        else
            return 0;
    }
    if(dp[i][make]!=-1)
    {
        return dp[i][make];
    }
    if(make-arr[i]>=0)
    {
        ret_1=call(i,make-arr[i]);

    }
    ret_2=call(i+1,make);
    dp[i][make]=ret_1+ret_2;
    return dp[i][make];
}
int main()
{
    long long int l,x,y;
    for(x=0; x<5; x++)
    {
        for(y=0; y<7490; y++)
        {
            dp[x][y]=-1;
        }
    }
    call(0,7489);
    while(scanf("%lld",&n)!=EOF)
    {


        l=call(0,n);
        printf("%lld\n",l);
    }
    return 0;
}
