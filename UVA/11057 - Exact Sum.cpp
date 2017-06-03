#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll ans,arr[10009],n;

bool BinarySearch(ll i, ll b)
{
    ll mid,left,right;
    left=i;
    right=n;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(arr[mid]==b)
        {
            ans=mid;
            return true;
        }
        else if(arr[mid]<b)
            left=mid+1;
        else
            right=mid-1;
    }
    return false;
}

int main()
{
    ll m,i,j,a,b;
    while(scanf("%lld",&n)!=EOF)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&arr[i]);
        }
        scanf("%lld",&m);
        ans=0;
        a=0;
        b=pow(10,12);
        sort(arr,arr+n+1);
        for(i=1; i<n; i++)
        {
            if(BinarySearch(i,m-arr[i]))
            {
                b=arr[ans];
                a=arr[i];
            }
        }
        printf("Peter should buy books whose prices are %lld and %lld.\n\n",a,b);
    }
    return 0;
}
