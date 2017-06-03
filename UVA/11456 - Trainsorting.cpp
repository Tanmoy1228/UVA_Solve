#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,j,A[2009],I[2009],L[2009],L1[2009],l,h,m,lis,t,T;
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld",&n);
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        for(i=1; i<=n; i++)
            scanf("%lld",&A[i]);
        lis=0;
        I[0]=-99999999999;
        for(i=1; i<=n; i++)
            I[i]=9999999999;
        for(i=n; i>0; i--)
        {
            l=0;
            h=lis;
            while(l<=h)
            {
                m=(l+h)/2;
                if(I[m]<A[i])
                    l=m+1;
                else
                    h=m-1;
            }
            I[l]=A[i];
            L[i]=l;
            lis=max(l,lis);
        }
        lis=0;
        I[0]=99999999999;
        for(i=1; i<=n; i++)
            I[i]=-9999999999;
        for(i=n; i>0; i--)
        {
            l=0;
            h=lis;
            while(l<=h)
            {
                m=(l+h)/2;
                if(I[m]>A[i])
                    l=m+1;
                else
                    h=m-1;
            }
            I[l]=A[i];
            L1[i]=l;
            lis=max(l,lis);
        }
        lis=0;
        for(i=1; i<=n; i++)
            lis=max(lis,L[i]+L1[i]);
        printf("%lld\n",lis-1);
    }
    return 0;
}
