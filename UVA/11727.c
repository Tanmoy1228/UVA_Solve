#include<stdio.h>
int main()
{
    int t=1, T;
    scanf("%d", &T);
    while(t<=T)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if((b>a && a>c) || (c>a && a>b))
        {
            printf("Case %d: %d\n", t, a);
        }
        else if((a>b && b>c) || (c>b && b>a))
        {
            printf("Case %d: %d\n", t, b);
        }
        else if((a>c && c>b) || (b>c && c>a))
        {
            printf("Case %d: %d\n", t, c);
        }
        t++;
    }
    return 0;
}
