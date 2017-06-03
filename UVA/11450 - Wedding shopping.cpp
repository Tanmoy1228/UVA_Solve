#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,m,dp[22][202];
vector<ll>arr[22];

ll call(ll i, ll sum)
{
    ll ans=999999999;
    if(sum<0)
        return 9999;
    if(i==n)
        return sum;

    if(dp[i][sum]!=-1)
        return dp[i][sum];
    for(int j=0; j<arr[i].size(); j++)
        ans=min(ans,call(i+1,sum-arr[i][j]));
    return dp[i][sum]=ans;
}

int main()
{
    ll t,i,j,c,ans,a;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        memset(dp,-1,sizeof dp);
        for(i=0; i<n; i++)
        {
            cin>>c;
            arr[i].clear();
            for(j=1; j<=c; j++)
            {
                cin>>a;
                arr[i].push_back(a);
            }
        }
        ans=call(0,m);
        if(ans>=m)
            cout<<"no solution\n";
        else
            cout<<m-ans<<endl;
//        for(i=0; i<n; i++)
//        {
//            for(j=0; j<=m; j++)
//                cout<<dp[i][j]<<" ";
//            cout<<endl;
//        }
    }
    return 0;
}
