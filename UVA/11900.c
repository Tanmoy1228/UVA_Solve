#include<stdio.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        int n,m,p,q,i,a=0,b=0,v[10000];
        scanf("%d %d %d",&n,&p,&q);
        for(i=0;i<n;i++)
        {
            scanf("%d",&v[i]);
        }
        if(p>=n)
        {
            m=n;
        }
        else
        {
            m=p;
        }
        for(i=0;i<n,i<m;i++)
        {
            a=a+v[i];
            if(a>q)
            {
                break;
            }
            b++;
        }
        printf("Case %d: %d\n",t,b);
        t++;
    }
    return 0;
}
