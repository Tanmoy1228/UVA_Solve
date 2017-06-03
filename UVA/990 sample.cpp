#include<bits/stdc++.h>
using namespace std;
long long int time1,w,c,treasure,depth[40],quantity[40],dp[32][1009],ans2[40];

long long int knapsak(long long int i, long long int time2)
{
    int r1=0,r2=0;
    if(i>treasure)
        return 0;
    else if(dp[i][time2]!=0)
        return dp[i][time2];
    else if(time2+depth[i]<=time1)
    {
        r1=quantity[i]+knapsak(i+1,time2+depth[i]);
    }
    r2=knapsak(i+1,time2);

    return dp[i][time2]=max(r1,r2);
}

void backTrack(long long int i, long long int time2)
{
    if(i>treasure)
        return;
    else if(time2+depth[i]<=time1)
    {
        //cout<<i<<" "<<time2<<" "<<dp[i][time2]<<" "<<dp[i+1][time2+depth[i]]<<endl;
        if(dp[i][time2]==dp[i+1][time2+depth[i]]+quantity[i])
        {
            ans2[i]=1;
            c++;
            backTrack(i+1,time2+depth[i]);
        }
        else
        {
            backTrack(i+1,time2);
        }
    }
    else
    {
        backTrack(i+1,time2);
    }
}

int main()
{
    long long int i,ans,t=0;
    while(cin>>time1>>w)
    {
        cin>>treasure;
        memset(dp,0,sizeof dp);
        memset(ans2,-1,sizeof ans2);
        for(i=1; i<=treasure; i++)
        {
            cin>>depth[i]>>quantity[i];
            depth[i]*=3*w;
        }
        c=0;
        if(t!=0)
            cout<<endl;
        t++;
        ans=knapsak(1,0);
        backTrack(1,0);

        cout<<ans<<endl<<c<<endl;
        for(i=1; i<=treasure; i++)
            if(ans2[i]==1)
                cout<<depth[i]/(3*w)<<" "<<quantity[i]<<endl;
    }
    return 0;
}
