#include<stdio.h>
float f_91(float x);
int main()
{
    int n, i;
    while(scanf("%d", &n)==1)
    {
        if(n==0)
        {
            break;
        }
        else if(n<=100)
        {
            printf("f91(%d) = 91\n", n);
        }
        else if(n>=101)
        {
            i = n-10;
            printf("f91(%d) = %d\n", n, i);
        }
    }
    return 0;
}
