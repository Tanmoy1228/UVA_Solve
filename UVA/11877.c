#include<stdio.h>
int main()
{
    int t=1, n;
    while(t<=10 && t++)
    {
        scanf("%d", &n);
        if(n==0)
        {
            break;
        }
        else
        {
            int c=0;
            while(n>2)
            {
                n=n-3;
                n=n+1;
                c++;
            }
            if(n==2)
            {
                c++;
            }
            printf("%d\n", c);
        }
    }
    return 0;
}
