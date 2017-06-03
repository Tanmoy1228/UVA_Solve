#include<bits/stdc++.h>
using namespace std;
long long int arr2[205],finish,start,n;
long long int kadane(long long int x, long long int y)
{
    long long int i,a=0,maxi=-1;
    for(i=1; i<=n; i++)
    {
        if(arr2[i]==x-y+1)
        {
            a+=arr2[i];
        }
        else
            a=0;
        if(a>maxi)
        {
            maxi=a;
        }
    }
    return maxi;
}
int main()
{
    long long int a,t,T,m,i,j,k,l,arr[205][205],sum;
    scanf("%lld",&T);
    getchar();
    string s;
    for(t=1; t<=T; t++)
    {
        if(t>1)
            printf("\n");
        getchar();
        cin>>s;
        l=s.length();
        a=0;
        //memset(arr1,0,sizeof arr1);
        for(i=0; i<l; i++)
        {
            if(s[i]=='0')
                arr[1][i+1]=0;
            else
                arr[1][i+1]=1;
        }
        n=l;
        for(i=2; i<=n; i++)
        {
            cin>>s;
            for(j=0; j<n; j++)
            {
                if(s[j]=='0')
                    arr[i][j+1]= 0;
                else
                    arr[i][j+1]=1;
            }
        }
        sum=-1;
        for(k=1; k<=n; k++)
        {
            memset(arr2,0,sizeof arr2);
            for(i=k; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                    arr2[j]+=arr[i][j];

                m=kadane(i,k);
                sum=max(sum,m);
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
