#include<stdio.h>
#include<math.h>
unsigned long long fact(int x);
int main()
{
    int n,j;
    j=fabs(n);
    while(scanf("%d", &n)==1)
    {
        unsigned long long b;
        j=fabs(n);
        if(n<0 && j%2==1)
        {
            printf("Overflow!\n");
        }
        else if(n<0 && j%2==0)
        {
            printf("Underflow!\n");
        }
        else if(n>13)
        {
            printf("Overflow!\n");
        }
        else if(n<8)
        {
            printf("Underflow!\n");
        }
        else
        {
            b=fact(n);
            printf("%llu\n",b);
        }
    }
    return 0;
}
unsigned long long fact(int x)
{
    unsigned long long i,a=1;
    for(i=1;i<=x;i++)
    {
        a=a*i;
    }
    return a;
}

