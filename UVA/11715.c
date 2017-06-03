#include<stdio.h>
#include<math.h>
int main()
{
    int c=1,n;
    while(scanf("%d",&n)!=EOF)
    {
        double u,v,a,s,t;
        if(n==1)
        {
            scanf("%lf %lf %lf",&u,&v,&t);
            s=0.5*t*(v+u);
            a=(v-u)/t;
            printf("Case %d: %0.3lf %0.3lf\n",c,s,a);
            c++;
            continue;
        }
        else if(n==2)
        {
            scanf("%lf %lf %lf",&u,&v,&a);
            s=(v*v-u*u)/(2*a);
            t=(v-u)/a;
            printf("Case %d: %0.3lf %0.3lf\n",c,s,t);
            c++;
            continue;
        }
        else if(n==3)
        {
            scanf("%lf %lf %lf",&u,&a,&s);
            v=sqrt(2*a*s+u*u);
            t=(v-u)/a;
            printf("Case %d: %0.3lf %0.3lf\n",c,v,t);
            c++;
            continue;
        }
        else if(n==4)
        {
            scanf("%lf %lf %lf",&v,&a,&s);
            u=sqrt(v*v-2*a*s);
            t=(v-u)/a;
            printf("Case %d: %0.3lf %0.3lf\n",c,u,t);
            c++;
            continue;
        }
    }
    return 0;
}
