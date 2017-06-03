#include<stdio.h>
#include<math.h>
int main()
{
    double l,f;
    while(scanf("%lf %lf",&l,&f)!=EOF)
    {
        if(l==0 && f==0)
        {
            break;
        }
        double n,v;
        v=sqrt(2*f*l);
        n=v*3600/(2*l);
        printf("%0.8lf %0.8lf\n",v,n);
    }
    return 0;
}
