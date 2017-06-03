#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main()
{
    double a,b,c;
    while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
    {
        double tri_a,i_c_a,i_c_r,o_c_a,o_c_r,s,su,r,v;
        s=(a+b+c)/2;
        tri_a=sqrt(s*(s-a)*(s-b)*(s-c));
        i_c_r=tri_a/s;
        i_c_a=PI*pow(i_c_r,2);
        o_c_r=(a*b*c)/(4*tri_a);
        o_c_a=PI*pow(o_c_r,2);
        r=i_c_a;
        v=tri_a-i_c_a;
        su=o_c_a-tri_a;
        printf("%0.4lf %0.4lf %0.4lf\n",su,v,r);
    }
    return 0;
}
