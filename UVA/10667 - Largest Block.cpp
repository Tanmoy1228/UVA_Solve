#include<bits/stdc++.h>
using namespace std;
long long int n,arr2[105];
long long int kadane(long long int x, long long int y)
{
    long long int a,i,maxi;
    maxi=-1;
    a=0;
    for(i=1; i<=n; i++)
    {
        if(arr2[i]==y-x+1)
            a+=arr2[i];
        else
            a=0;
        if(a>maxi)
            maxi=a;
    }
    //cout<<maxi<<endl;
    return maxi;
}
int main()
{
    long long int t,T,m,b,i,j,k,x1,y1,x2,y2,sum,arr[105][105];
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld %lld",&n,&b);
        //memset(arr,0,sizeof arr);
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                arr[i][j]=1;
        for(i=1; i<=b; i++)
        {
            scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
            for(j=x1; j<=x2; j++)
            {
                for(k=y1; k<=y2; k++)
                {
                    arr[j][k]=0;
                }
            }
        }
        sum=-1;
        for(i=1; i<=n; i++)
        {
            memset(arr2,0,sizeof arr2);
            for(j=i; j<=n; j++)
            {
                for(k=1; k<=n; k++)
                {
                    arr2[k]+=arr[j][k];
                }
                sum=max(sum,kadane(i,j));
            }
        }
        printf("%lld\n",sum);
    }
}
