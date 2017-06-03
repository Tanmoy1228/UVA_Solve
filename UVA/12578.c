#include<stdio.h>
#include<math.h>
#define pi acos(-1);
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double l,a,c;
        scanf("%lf",&l);
        a=l*l*(3.0/5);
        c= acos(-1.0)*pow((l*(1.0/5)),2);
        printf("%0.2lf %0.2lf\n",c,a-c);
    }
    return 0;
}
