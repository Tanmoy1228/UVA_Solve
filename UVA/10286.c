#include<stdio.h>
int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF)
    {
        double l,m=1.067395682;
        l=m*n;
        printf("%0.10lf\n",l);
    }
    return 0;
}
