#include<stdio.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        int n,i,x=0,y=0,a[100];
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n-1;i++)
        {
            if(a[i]<a[i+1])
            {
                x++;
            }
            else if(a[i]>a[i+1])
            {
                y++;
            }
        }
        printf("Case %d: %d %d\n",t,x,y);
        t++;
    }
    return 0;
}
