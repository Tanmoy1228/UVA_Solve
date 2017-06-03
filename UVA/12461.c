#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        printf("1/2\n");
    }
    return 0;
}

