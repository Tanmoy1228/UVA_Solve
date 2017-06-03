#include<stdio.h>
int main()
{
    int t=1, n, i, sum;
    printf("PERFECTION OUTPUT\n");
    while(t<100)
    {
        scanf("%d", &n);
        if(n==0)
        {
            break;
        }
        else
        {
            sum=0;
            for(i=1; i<=n/2; i++)
            {
                if(n%i==0)
                {
                    sum = sum+i;
                }
            }
            if(n==sum)
            {
                printf("%5d  PERFECT\n", n);
            }
            else if(n<sum)
            {
                printf("%5d  ABUNDANT\n", n);
            }
            else if(n>sum)
            {
                printf("%5d  DEFICIENT\n", n);
            }
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
