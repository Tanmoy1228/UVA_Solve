#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[52][52],n,m,k;

ll call(ll i, ll j)
{
    ll sum=0;

    if(i>n || j>k)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(i==n && j==k)
        return 1;

    for(ll l=1;l<=m;l++)
    {
        sum+=call(i+l,j+1);
    }
    //cout<<i<<" "<<j<<" "<<sum<<endl;

    return dp[i][j]=sum;
}

int main()
{
    while(cin>>n>>k>>m)
    {
        memset(dp,-1,sizeof dp);
        cout<<call(0,0)<<endl;
    }
    return 0;
}
