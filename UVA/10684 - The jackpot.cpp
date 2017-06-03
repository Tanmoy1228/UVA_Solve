#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int finish,n,maxi,a,i,arr[20009];
    while(scanf("%lld",&n) && n)
    {
        for(i=1; i<=n; i++)
            scanf("%lld",&arr[i]);
        maxi=0;
        a=0;
        finish = -1;
        for(i=1; i<=n; i++)
        {
            a+=arr[i];
            if(a<0)
                a=0;
            else if(a>maxi)
            {
                maxi=a;
                finish=i;
            }
        }
        if(finish==-1)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %lld.\n",maxi);
    }
}
