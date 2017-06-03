#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100000

ll A[MAX+5],B[MAX+5],n;

void precal()
{
    ll i;
    memset(A,0,sizeof A);
    for(i=1;i<=MAX;i++)
    {
        A[i]=A[i-1]+1;
        if(i>9)
            A[i]++;
        if(i>99)
            A[i]++;
        if(i>999)
            A[i]++;
        if(i>9999)
            A[i]++;
        if(i>99999)
            A[i]++;
        B[i]=A[i];
    }
    for(i=1;i<=MAX;i++)
    {
        A[i]+=A[i-1];
    }
}

ll bal(ll n,ll m)
{
    if(n==0)
        return m%10;
    ll i,total=0;
    for(i=1;i<=m+1;i++)
    {
        total=B[i];
        if(total>=n)
            break;
    }
    total=n-B[i-1];

    //cout<<i<<" "<<total<<endl;
    n=B[i]-B[i-1];
    total=n-total;

    while(total--)
        i=i/10;
    return i%10;
}

ll Binary(ll n)
{
    ll low,high,mid,ans,pos;
    ans=0;
    pos=0;
    low=1;
    high=MAX;

    while(low<=high)
    {
        mid=(low+high)/2;
        if(A[mid]<=n)
        {
            low=mid+1;
            pos=mid;
        }
        else
        {
            high=mid-1;
        }
    }
    ans=A[pos];
    //cout<<ans<<" "<<pos<<endl;
    ans=bal(n-ans,pos);

    return ans;
}

int main()
{
    ll t,n,i,j,ans=0;
    scanf("%lld",&t);
    precal();
    while(t--)
    {
        scanf("%lld",&n);
        ans=Binary(n);
        printf("%lld\n",ans);
    }
    return 0;
}
