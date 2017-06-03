#include <bits/stdc++.h>
#define ll long long int
#define MX 1000009
using namespace std;

ll DivisorNo[MX],A[MX],k;

void NoOfDivisor_N_logN(ll N)
{
    ///calculate NoOfDivisor upto N in NlogN time
    memset(DivisorNo,0,sizeof DivisorNo);
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = i; j <= N; j += i)
        {
            DivisorNo[j] += 1;
        }
    }
}

void pre()
{
    ll i,j,a=1;
    A[1]=0;
    A[2]=1;
    for(k=3;k<MX;k++)
    {
        j=k-1;
//        cout<<j<<" "<<a<<endl;
        a=A[j]+DivisorNo[A[j]];
        A[k]=a;
        if(a>1000000)
            return;
    }
}

ll upbinary(ll a)
{
    ll i,low,high,mid,ans;

    low=1;
    high=k;
    ans=1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(A[mid]<a)
        {
            low=mid+1;
            ans=mid;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}

ll lowbinary(ll a)
{
    ll i,low,high,mid,ans;

    low=1;
    high=k;
    ans=1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(A[mid]<=a)
        {
            low=mid+1;
            ans=mid;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}


int main()
{
    ll t,T,i,j,ans,m,a,b;
    NoOfDivisor_N_logN(MX);
    pre();
    k++;
//    sort(A,A+k);
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld %lld",&a,&b);

        ans=lowbinary(b);
//        cout<<ans<<endl;
        ans-=upbinary(a);

        printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}

