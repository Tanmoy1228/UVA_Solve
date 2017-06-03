#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c;
    while(scanf("%lf %lf %lf",&a,&b,&c) !=EOF)
    {
        double s,area;
        if(a>b+c || b>c+a || c>a+b)
        {
            printf("-1.000\n");
        }
        else if(a==0 || b==0 || c==0)
        {
            printf("-1.000\n");
        }
        else
        {
            s=(a+b+c)/2;
            area=4*(sqrt(s*(s-a)*(s-b)*(s-c)))/3;
            if(area<=0)
            {
                printf("-1.000\n");
            }
            else
            {
                printf("%0.3lf\n",area);
            }
        }
    }
    return 0;
}
