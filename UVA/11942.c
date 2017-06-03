#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    printf("Lumberjacks:\n");
    while(t--)
    {
        int a[100],i,j=0,temp;
        for(i=0;i<10;i++)
        {
            scanf("%d",&a[i]);
        }
        if(a[0]>a[1])
        {
            for(i=0;i<9;i++)
            {
                if(a[i]<a[i+1])
                {
                    printf("Unordered\n");
                    j=1;
                    break;
                }
            }
            if(j==1)
            {
                continue;
            }
            else
            {
                printf("Ordered\n");
            }
        }
        else if(a[0]<a[1])
        {
            for(i=0;i<9;i++)
            {
                if(a[i]>a[i+1])
                {
                    printf("Unordered\n");
                    j=1;
                    break;
                }
            }
            if(j==1)
            {
                continue;
            }
            else
            {
                printf("Ordered\n");
            }
        }
    }
    return 0;
}
