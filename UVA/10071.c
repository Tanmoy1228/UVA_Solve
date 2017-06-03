#include<stdio.h>
int main()
{
    int *v, t, s, test;
    while(scanf("%d %d", &*v, &t)==2)
    {
        s = 2**v*t;
        printf("%d",s);
    }
    return 0;
}
