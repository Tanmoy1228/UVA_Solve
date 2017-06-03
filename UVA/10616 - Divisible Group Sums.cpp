#include<bits/stdc++.h>
using namespace std;
long long int dp[201][11][21],A[205],n,d;

long long mod(long long a,long long b)
{
    long long c;

    if(a<b)
    {
        a=-a;
        c=a%b;
        c=b-c;
    }
    else
        c=a;
    return c%b;
}
long long int knapsak(long long int i, long long int j, long long int m)
{
    long long int r1=0,r2=0,k;
    k=mod(A[i]+m,d);
    if(j==0 && m%d==0 && m!=0)
    {
        //cout<<A[i-1]<<endl;
        return 1;
    }
    if(i>n)
        return 0;
    if(j<0)
        return 0;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    //cout<<i<<" "<<j<<" "<<A[i]<<" "<<m<<endl;
    r1=knapsak(i+1,j-1,m+A[i]);
    r2=knapsak(i+1,j,m);
    return dp[i][j][k]=r1+r2;
}
int main()
{
    long long int q,m,i,j,t=1,k,ans;
    while(scanf("%lld %lld",&n,&q)!=EOF)
    {
        if(n==0 && q==0)
            break;
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&A[i]);
        }
        printf("SET %lld:\n",t);
        t++;
        for(i=1; i<=q; i++)
        {
            memset(dp,-1,sizeof dp);
            scanf("%lld %lld",&d,&m);
            ans=knapsak(1,m,0);
            printf("QUERY %lld: %lld\n",i,ans);
        }
    }
    return 0;
}
