#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll A[10000009];
int main()
{
    ll j,a,ans,i=0;
    while(scanf("%lld",&A[0]) && A[0])
    {
        i=1;
        while(scanf("%lld",&A[i]) && A[i])
            i++;
        ans=A[1]-A[0];
        for(j=1;j<i;j++)
        {
            a=abs(A[j]-A[j-1]);
            //cout<<a<<endl;
            ans=__gcd(ans,a);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
