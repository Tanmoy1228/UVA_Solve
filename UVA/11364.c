#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,a[100],i,x,y,max,min;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        max=a[0];
        min=a[0];
        for(i=1;i<n;i++)
        {
            if(a[i]>max)
            {
                max=a[i];
            }
            else if(a[i]<min)
            {
                min=a[i];
            }
        }
        x=max-a[0];
        y=a[0]-min;
        printf("%d\n",2*(x+y));
    }
    return 0;
}
