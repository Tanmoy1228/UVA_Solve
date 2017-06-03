#include<bits/stdc++.h>
using namespace std;
long long int arr2[205],finish,start,n;
long long int kadane()
{
    long long int i,a=0,fst,maxi=-1;
    fst=1;
    for(i=1;i<=n;i++)
    {
        a+=arr2[i];
        if(a<0)
        {
            a=0;
            fst=i+1;
        }
        else if(maxi<=a)
        {
            maxi=a;
            finish=i;
            start=fst;
        }
    }
    return maxi;
}
int main()
{
    long long int m,i,j,k,l,arr[205][205],finalleft,finalright,finalstart,finalfinish,mini,sum;
    while(scanf("%lld",&n)==1)
    {
        mini=-99999999999;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%lld",&arr[i][j]);
                mini=max(mini,arr[i][j]);
            }
        }
        sum=-1;
        for(k=1;k<=n;k++)
        {
            memset(arr2,0,sizeof arr2);
            for(i=k;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                    arr2[j]+=arr[i][j];
                m=kadane();
                if(m>sum)
                {
                    sum=m;
                    finalleft=k;
                    finalright=i;
                    finalstart=start;
                    finalfinish=finish;
                }
            }
        }
        if(sum==-1)
            printf("%lld\n",mini);
        else
            printf("%lld\n",sum);
    }
    return 0;
}
