#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ll n,m,i,j,ans;
    while(scanf("%lld",&n)!=EOF)
    {
        ans=1;
        for(i=1;i<10000;i++)
        {
            ans=ans*10+1;
            ans=ans%n;
            if(ans==0)
                break;
        }
        if(n==1)
            i=0;
        printf("%lld\n",i+1);
    }

    return 0;
}

