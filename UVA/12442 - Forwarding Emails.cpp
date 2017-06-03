#include<bits/stdc++.h>
using namespace std;
vector<long long int > arr;
bool visit[50009];
long long int counter,v[50009],dp[50009];
long long int dfs(long long int x)
{
    long long int y,i,j;
//    if(dp[x]!=-1)
//        return dp[x];
    y=v[x];
    visit[x]=true;
    if(!visit[y] && v[x]!=-1)
        j=dfs(y)+1;
    else
        j=0;
    visit[x]=false;
    return dp[x]=j;
}
int main()
{
    long long int t,T,n,i,j,a,b,ans,maxi;
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld",&n);
        arr.clear();
        for(i=1; i<=n; i++)
            v[i]=-1;
        memset(visit,false,sizeof visit);
        for(i=1; i<=n; i++)
        {
            scanf("%lld %lld",&a,&b);
            if(!visit[a])
                arr.push_back(a);
            if(!visit[b])
                arr.push_back(b);
            visit[a]=true;
            visit[b]=true;
            v[a]=b;
        }
        maxi=-1;
        memset(dp,-1,sizeof dp);
        memset(visit,false,sizeof visit);
        sort(arr.begin(),arr.begin()+arr.size());
        for(i=0; i<arr.size(); i++)
        {
            if(dp[arr[i]]==-1)
            {
                //memset(visit,false,sizeof visit);
                counter=dfs(arr[i]);
                dp[arr[i]]=counter;
            }
            if(dp[arr[i]]>maxi)
            {
                maxi=dp[arr[i]];
                ans=arr[i];
            }
        }
        printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}
