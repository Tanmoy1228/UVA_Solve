#include<stdio.h>
int main()
{
    int n, m;
    while(scanf("%d %d", &m, &n)==2)
    {
        if(n>=1 && n<=300 && m>=1 && m<=300)
        {
            printf("%d\n", n*m-1);
        }
    }
    return 0;
}
