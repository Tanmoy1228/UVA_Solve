#include<bits/stdc++.h>
using namespace std;
long long int A[20000005],I[20000005],L[20000005],LisSequence[20000005];
int main()
{
    long long int n,i,j;
    i=1;

    while(scanf("%lld",&n)!=EOF)
    {
        A[i]=n;
        i++;
    }
    n=i-1;
    long long int lis=0;
    I[0]=-999999999999;
    for(i=1; i<=n; i++)
    {
        I[i]=9999999999999;
    }
    for(i=1,j=1; i<=n; i++)
    {
        long long int l,h,mid;
        l=0;
        h=lis;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(I[mid]<A[i])
                l=mid+1;
            else
                h=mid-1;
        }
        I[l]=A[i];
        L[i]=l;
        if(l>=lis)
            lis=l;
    }
    printf("%lld\n",lis);
    printf("-\n");
    i = 0;
    for(j=1;j<=n;j++)
        if( L[j] > L[i] )
            i = j;
    int top = L[i] - 1;
    LisSequence[top] = A[i];
    top--;
    for(j=i-1;j>=0;j--)
    {
        if( A[j] < A[i] && L[j] == L[i] - 1 )
        {
            i = j; // as in our algorithm
            LisSequence[top] = A[i]; // stored
            top--; // decreased for new items
        }
    }

    for(i=0; i<lis; i++)
        printf("%lld\n",LisSequence[i]);
    return 0;
}

