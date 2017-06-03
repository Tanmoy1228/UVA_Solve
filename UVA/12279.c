#include<stdio.h>
int main()
{
    int n,a[10000],t=1,i;
    while(scanf("%d",&n))
    {
        int x=0,y=0;
        if(n==0)
        {
            break;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                x++;
            }
            else
            {
                y++;
            }
        }
        printf("Case %d: %d\n",t,y-x);
        t++;
    }
    return 0;
}
