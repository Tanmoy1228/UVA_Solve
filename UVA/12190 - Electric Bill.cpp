#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll n,cost[]= {2,3,5,7};

ll calculate(ll a, ll b, ll c, ll i)
{
    //cout<<a<<" "<<b<<" "<<c<<" "<<i<<endl;
    if(i==3)
        return a/cost[i];
    if(a>b*cost[i])
        return calculate(a-(b*cost[i]), (b+c)*100-b-c, b+c, i+1)+b;
    return a/cost[i];
}

ll calculate1(ll a, ll b, ll c, ll i)
{
    //cout<<a<<" "<<b<<" "<<c<<" "<<i<<endl;
    if(i==3)
        return a*cost[i];
    if(a>b)
        return calculate1(a-b, (b+c)*100-b-c,b+c, i+1)+b*cost[i];
    return a*cost[i];
}

ll BinarySearch(ll total,ll b)
{
    ll mid,ans,left,right,a;
    left=1;
    right=total;

    while(left<=right)
    {
        mid=(left+right)/2;
        //cout<<mid<<endl;
        a=calculate1(total-mid,100,0,0)-calculate1(mid,100,0,0);
        //cout<<calculate1(total-mid,100,0,0)<<" "<<calculate1(mid,100,0,0)<<" "<<mid<<" "<<a<<endl;
        if(a<=b)
        {
            right=mid-1;
            if(a==b)
                ans=mid;
        }
        else
            left=mid+1;
    }
    return ans;
}

int main()
{
    ll t,T,i,ans,a,b,total;
    while(scanf("%lld %lld",&a,&b) && a && b)
    {
        total=calculate(a,100,0,0);
        ans=BinarySearch(total,b);
        printf("%lld\n",calculate1(ans,100,0,0));
    }
    return 0;
}

