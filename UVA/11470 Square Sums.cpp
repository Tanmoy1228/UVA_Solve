#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int arr[11][11];
int call(int i, int j)
{
    int x,y,total_1=0,total_2=0,total=0,k;
    if(i==j)
    {
        return arr[i][j];
    }
    x=max(i,j);
    y=min(i,j);
    for(k=y;k<=x;k++)
    {
        total_1=total_1+arr[i][k];
        total_2=total_2+arr[k][i];
    }

    total=total_1+total_2;
    total_1=0;
    total_2=0;
    for(k=y;k<=x;k++)
    {
        total_1=total_1+arr[j][k];
        total_2=total_2+arr[k][j];
    }

    total=total_1+total_2+total-arr[i][i]-arr[j][j]-arr[i][j]-arr[j][i];

    return total;
}

int main()
{
    int n,t=0;
    while(scanf("%d",&n))
    {
        t++;
        if(n==0)
        {
            break;
        }
        int i,j,m;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        printf("Case %d:",t);
        for(i=1,j=n;i<=j;i++,j--)
        {
            m=call(i,j);
            printf(" %d",m);
        }
        printf("\n");
    }
    return 0;
}
