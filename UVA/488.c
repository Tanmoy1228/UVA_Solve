#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,i,j,k;
        scanf("%d %d",&n,&m);
        for(k=1;k<m;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=i;j++)
                {
                    printf("%d",i);
                }
                printf("\n");
            }
            for(i=n-1;i>0;i--)
            {
                for(j=1;j<=i;j++)
                {
                    printf("%d",i);
                }
                printf("\n");
            }
            printf("\n");
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                printf("%d",i);
            }
            printf("\n");
        }
        for(i=n-1;i>0;i--)
        {
            for(j=1;j<=i;j++)
            {
                printf("%d",i);
            }
            printf("\n");
        }
        if(t>0)
        {
            printf("\n");
        }
    }
    return 0;
}
