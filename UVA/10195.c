#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c;
    while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
    {
        double area,s;
        if(a>b+c || b>c+a|| c>a+b)
        {
            break;
        }
        else if(a==0 || b==0 || c==0)
        {
            printf("The radius of the round table is: 0.000\n");
        }
        else
        {
            s=(a+b+c)/2;
            area=(sqrt(s*(s-a)*(s-b)*(s-c)))/s;
            printf("The radius of the round table is: %0.3lf\n",area);
        }
    }
    return 0;
}
