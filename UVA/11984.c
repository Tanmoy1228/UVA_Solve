#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    if(t<=100)
    {
        int i, C, d;
        float c;
        for(i=1; i<=t; i++)
        {
            scanf("%d %d", &C, &d);
            if(C>=0 && d<=100)
            {
                c = (float) d/180*100;
                c = c + C;
                printf("Case %d: %0.2f\n", i, c);
            }
        }
    }
    return 0;
}
