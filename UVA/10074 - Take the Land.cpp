#include<bits/stdc++.h>
using namespace std;
long long int arr2[105],n,m;
long long int kadane(long long int x, long long int y)
{
    long long int i,a=0,maxi=-1;
    for(i=1;i<=n;i++)
    {
        //cout<<arr2[i]<<endl;
        if(arr2[i]==x-y+1)
            a+=arr2[i];
        else
            a=0;
        if(a>maxi)
            maxi=a;
    }
    return maxi;
}
int main()
{
    long long int a,i,j,k,sum,arr[105][105];
    while(scanf("%lld %lld",&m,&n)==2 && m && n)
    {
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%lld",&a);
                if(a==0)
                    arr[i][j]=1;
                else
                    arr[i][j]=0;
            }
        }
        sum=-1;
        for(k=1;k<=m;k++)
        {
            memset(arr2,0,sizeof arr2);
            for(i=k;i<=m;i++)
            {
                for(j=1;j<=n;j++)
                    arr2[j]+=arr[i][j];
                sum=max(sum,kadane(i,k));
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
