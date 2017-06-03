#include<bits/stdc++.h>
using namespace std;
long long int n,m,arr2[1005][1005],arr3[1005][1005],arr[1005][1005];
long long int kadane()
{
    long long int i,maxi=0;
    for(i=0; i<m; i++)
        //maxi+=arr2[i];
    return maxi;
}
int main()
{
    long long int a,sum,i,j,k,l,z,t=0;
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        memset(arr,0,sizeof arr);
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                scanf("%lld",&arr[i][j]);
        sum=0;
        for(k=1; k<=n; k++)
        {
            for(j=1; j<=n; j++)
            {
                arr[k][j]+=arr[k][j-1];
            }
        }
        for(k=1; k<=n; k++)
        {
            for(j=1; j<=n; j++)
            {
                arr[k][j]+=arr[k-1][j];
            }
        }
//        for(k=1; k<=n; k++)
//        {
//            for(j=1; j<=n; j++)
//            {
//                cout<<arr[k][j]<<" ";
//            }
//            cout<<endl;
//        }
        if(t>0)
            printf("\n");
        t++;
        for(k=m; k<=n; k++)
        {
            for(j=m; j<=n; j++,l++)
            {
                //memset(arr2,0,sizeof arr2);
//                a=0;
//                for(i=0; i<m; i++)
//                {
//                    for(z=0; z<m; z++)
//                        a+=arr[k+i][j+z];
//                }
                //a=kadane();
                //cout<<arr[k-m][j-m]<<" "<<arr[k-m][j]<<" "<<arr[k][j-m]<<endl;
                a=arr[k][j]+arr[k-m][j-m]-arr[k-m][j]-arr[k][j-m];
                printf("%lld\n",a);
                sum+=a;
            }

        }
        printf("%lld\n",sum);
    }
    return 0;
}
