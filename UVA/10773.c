#include<stdio.h>
#include<math.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        double d,u,v,t1,t2,t3;
        scanf("%lf %lf %lf",&d,&v,&u);
        if(v>=u)
        {
            printf("Case %d: can't determine\n",t);
        }
        else
        {
            t1=d/u;
            t2=d/(sqrt(u*u-v*v));
            t3=t2-t1;
            if(t1==t2)
            {
                printf("Case %d: can't determine\n",t);
            }
            else
            {
                printf("Case %d: %0.3lf\n",t,t3);
            }
        }
        t++;
    }
    return 0;
}
