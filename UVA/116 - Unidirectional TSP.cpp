#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[12][102],dir[12][102],n,m,arr[12][102];

ll call(ll i, ll j)
{
    ll a,b,c,d;

    if(i>n)
        return pow(10,15);
    if(j>m)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i>1 && i<n)
    {
        a=call(i-1,j+1)+arr[i][j];
        b=call(i,j+1)+arr[i][j];
        c=call(i+1,j+1)+arr[i][j];

        d=min(a, min(b,c));

        if(d==a)
        {
            dp[i][j]=d;
            dir[i][j]=i-1;
        }
        else if(d==b)
        {
            dp[i][j]=d;
            dir[i][j]=i;
        }
        else if(d==c)
        {
            dp[i][j]=d;
            dir[i][j]=i+1;
        }
    }
    if(i==1)
    {
        b=call(i,j+1)+arr[i][j];
        c=call(i+1,j+1)+arr[i][j];
        a=call(n,j+1)+arr[i][j];

        d=min(a, min(b,c));

        if(d==b)
        {
            dp[i][j]=d;
            dir[i][j]=i;
        }
        else if(d==c)
        {
            dp[i][j]=d;
            dir[i][j]=i+1;
        }
        else if(d==a)
        {
            dp[i][j]=d;
            dir[i][j]=n;
        }
    }
    else if(i==n)
    {
        c=call(1,j+1)+arr[i][j];
        a=call(i-1,j+1)+arr[i][j];
        b=call(i,j+1)+arr[i][j];

        d=min(a, min(b,c));

        if(d==c)
        {
            dp[i][j]=d;
            dir[i][j]=1;
        }
        else if(d==a)
        {
            dp[i][j]=d;
            dir[i][j]=i-1;
        }
        else if(d==b)
        {
            dp[i][j]=d;
            dir[i][j]=i;
        }
    }
    //cout<<i<<" "<<j<<" "<<dir[i][j]<<endl;

    return dp[i][j];
}

int main()
{
    ll i,j,a,maxi,start;
    while(cin>>n>>m)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                cin>>arr[i][j];
            }
        }
        memset(dp,-1,sizeof dp);
        memset(dir,0,sizeof dir);
        maxi=pow(10,15);
        for(i=1; i<=n; i++)
        {
            a=call(i,1);
            //cout<<a<<endl;
            if(a<maxi)
            {
                maxi=a;
                start=i;
            }
        }
        i=start;
        j=1;
        cout<<i;
        while(1)
        {
            if(j>=m)
            {
                break;
            }
            //cout<<i<<" "<<j<<" ";
            cout<<" "<<dir[i][j];
            //cout<<endl;
            i=dir[i][j];
            j++;
        }

        cout<<endl;
        cout<<maxi<<endl;
    }
    return 0;
}
