#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll arr[100005],n;

bool check(ll a)
{
    for(ll i=1;i<=n;i++)
    {
        if(arr[i]-arr[i-1]==a)
            a--;
        else if(arr[i]-arr[i-1]>a)
            return false;
    }
    return true;
}

ll BinarySearch()
{
    ll mid,left,right,ans;
    left=1;
    right=pow(10,15);

    while(left<=right)
    {
        mid=(left+right)/2;
        //cout<<mid<<endl;
        if(check(mid))
            right=mid-1,ans=mid;
        else
            left=mid+1;
    }
    return ans;
}

int main()
{
    ll t,T,i,ans;
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld",&n);
        arr[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        ans=BinarySearch();
        printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}
