#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,k,c=0,a[1000];
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(j=0;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(a[j]>a[k])
                {
                    c++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n",c);
    }
    return 0;
}
