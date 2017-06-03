#include<bits/stdc++.h>
#define ll long long int

using namespace std;

vector<ll>v;

int main()
{
    ll t,T,i,j,n,q,a;
    t=1;
    while(scanf("%lld %lld",&n,&q) && n && q)
    {
        v.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a);
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        printf("CASE# %lld:\n",t++);
        for(i=1;i<=q;i++)
        {
            scanf("%lld",&a);
            if(binary_search(v.begin(),v.end(),a))
            {
                j=upper_bound(v.begin(),v.end(),a-1)-v.begin();
                printf("%lld found at %lld\n",a,j+1);
            }
            else
                printf("%lld not found\n",a);
        }
    }
    return 0;
}
