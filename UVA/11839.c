#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,a[1000][100],x=0,y=0,c;
        if(n==0)
        {
            break;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<5;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=0;i<n;i++)
        {
            y=0;
            for(j=0;j<5;j++)
            {
                if(a[i][j]<=127)
                {
                    y++;
                    c=j;
                }
            }
            if(y==1)
            {
                if(c==0)
                {
                    printf("A\n");
                }
                else if(c==1)
                {
                    printf("B\n");
                }
                else if(c==2)
                {
                    printf("C\n");
                }
                else if(c==3)
                {
                    printf("D\n");
                }
                else if(c==4)
                {
                    printf("E\n");
                }
            }
            else
            {
                printf("*\n");
            }
        }
    }
    return 0;
}
