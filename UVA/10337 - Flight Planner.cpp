#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[12][1002],dp[12][1002],n;

ll call(ll i, ll j)
{
    ll a,b,c;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(j==n && i==9)
        return 0;
    if(i>=10 || j>=n || i<1)
        return pow(10,12);

    a=call(i-1,j+1)+60-arr[i][j];
    b=call(i,j+1)+30-arr[i][j];
    c=call(i+1,j+1)+20-arr[i][j];

    return dp[i][j]=min(a, min(b,c));
}

int main()
{
    ll t,i,j,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n=n/100;
        for(i=1;i<=10;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>arr[i][j];
            }
        }
        memset(dp,-1,sizeof dp);
        ans=call(9,2)  +  60-arr[10][1]  +  20-arr[9][n];
//        for(i=1;i<=10;i++)
//        {
//            for(j=1;j<=n;j++)
//            {
//                cout<<dp[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        cout<<ans<<endl<<endl;
    }
    return 0;
}
