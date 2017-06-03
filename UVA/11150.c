#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d", &n)==1)
    {
        int i, k=0;
        if(n>=1 && n<=200)
        {
            i = n;
            while(n>2)
            {
                n = n-3;
                n = n+1;
                k++;
            }
            if(n==2)
            {
                k++;
            }
            k = k+i;
        }
        printf("%d\n", k);
    }
    return 0;
}
