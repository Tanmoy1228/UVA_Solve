#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
        {
            break;
        }
        int a[100];
        int i,c=0,d,t=1,j,k,x=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(j=0;j<n;j++)
        {
            c=a[j]+c;
        }
        d=c/n;
        for(k=0;k<n;k++)
        {
            if(a[k]>d)
            {
                x=a[k]-d+x;
            }
        }
        printf("Set #%d\n",t);
        printf("The minimum number of moves is %d.\n\n",x);
        t++;
    }
    return 0;
}
