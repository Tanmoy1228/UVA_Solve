#include<bits/stdc++.h>
using namespace std;
long long int n,arr2[205];
long long int kadane()
{
    long long int fst=1,finish=-1,i,j=1,k,l,a=0,maxi=-99999;
    for(i=1; i<=n; i++)
        arr2[n+i]=arr2[i];
//    for(i=1;i<=2*n;i++)
//        cout<<arr2[i]<<" ";
//    cout<<endl;
    for(j=1; j<=n; j++)
    {
        a=0;
        for(i=j; i<n+j; i++)
        {
            a+=arr2[i];
            if(maxi<=a)
            {
                maxi=a;
            }
            else if(a<0)
            {
                a=0;
            }
        }
    }
    return maxi;
}
int main()
{
    long long int t,T,a,i,j,k,sum,arr[205][205];
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld",&n);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%lld",&arr[i][j]);
                arr[n+i][j]=arr[i][j];
            }
        }
//        for(i=1; i<=2*n; i++)
//        {
//            for(j=1; j<=n; j++)
//            {
//                cout<<arr[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        sum=-9999999;
        for(k=1; k<=n; k++)
        {
            memset(arr2,0,sizeof arr2);
            for(i=k; i<n+k; i++)
            {
                for(j=1; j<=n; j++)
                {
                    arr2[j]+=arr[i][j];
                }
                sum=max(sum,kadane());
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
