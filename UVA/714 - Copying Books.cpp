#include <bits/stdc++.h>
#define ll long long int
#define MX 1000009
using namespace std;

ll n,m,A[MX];

vector< ll >v1,v2;

bool check(ll mid)
{
    ll i,j;
    v1.clear();
    for(i=1,j=n; i<=m; i++)
    {
        ll page=mid;
        if(j>0)
        v1.push_back(j);
        while(page>=A[j] && j>0)
        {
            page-=A[j];
            j--;
            if(m-i==j)
            {
                break;
            }
        }
    }
    if(j==0)
    {
        v2.clear();
        v2=v1;
//        cout<<mid<<endl;
        return true;
    }
    else
        return false;
}

ll binary()
{
    ll low,high,mid,ans;

    low=0LL;
    high=10000000000LL;
    ans=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(check(mid))
        {
            high=mid-1;
            ans=mid;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}


int main()
{
    ll t,T,i,j,ans,a,b;
    scanf("%lld",&T);
//    freopen("out.txt","w",stdout);
    for(t=1; t<=T; t++)
    {
        scanf("%lld %lld",&n,&m);
        A[0]=0;
        for(i=1; i<=n; i++)
            scanf("%lld",&A[i]);

        ans=binary();

        reverse(v2.begin(),v2.end());

        for(i=0,j=1; i<v2.size(); i++)
        {
            a=v2[i];
            for(; j<=a; j++)
            {
                if(j==n)
                {
                    printf("%lld\n",A[j]);
                    j++;
                    break;
                }
                printf("%lld ",A[j]);
            }
            if(j!=n+1)
                printf("/ ");
        }

    }
    return 0;
}



