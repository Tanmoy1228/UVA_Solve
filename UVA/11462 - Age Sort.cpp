#include<bits/stdc++.h>
using namespace std;
long long int a[2000099];
int main()
{
    long long int n,i;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        for(i=0; i<n; i++)
        {
            scanf("%lld",&a[i]);
        }
        sort(a,a+n);
        for(i=0; i<n-1; i++)
        {
            printf("%lld ",a[i]);
        }
        printf("%lld\n",a[i]);
    }
    return 0;
}

