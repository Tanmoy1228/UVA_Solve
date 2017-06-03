#include<stdio.h>
#include<math.h>
int main()
{
    long long int n;
    while(scanf("%lld", &n)==1)
    {
        long long int i, j;
        if(n==0)
        {
            break;
        }
        i = sqrt(n);
        j = i*i;
        if(j==n)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
