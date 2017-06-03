#include<stdio.h>
int main()
{
    unsigned long int n, m;
    while(scanf("%lu %lu", &n, &m)==2)
    {
        int a, b, j=0, sum, c=0;
        if(n==0 && m==0)
        {
            break;
        }
        else
        {
            while(n!=0 || m!=0)
            {
                a = n%10;
                b = m%10;
                n = n/10;
                m = m/10;
                sum = a + b;
                j = (j+sum) /10;
                c = c+j;
            }
            if(c==0)
            {
                printf("No carry operation.\n");
            }
            else if(c>1)
            {
                printf("%d carry operations.\n", c);
            }
            else if(c==1)
            {
                printf("1 carry operation.\n");
            }
        }
    }
    return 0;
}
