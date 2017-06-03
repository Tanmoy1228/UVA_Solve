#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,T,a,b,c,ans;
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        ans=(c*(a+a-b))/(a+b);
        if(ans<=0)
            printf("0\n");
        else
            printf("%lld\n",ans);
    }
    return 0;
}
