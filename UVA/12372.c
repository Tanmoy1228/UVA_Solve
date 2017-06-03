#include<stdio.h>
int main()
{
    int t, T=1;
    scanf("%d", &t);
    while(T<=t)
    {
        int L, W, H;
        scanf("%d %d %d", &L, &W, &H);
        if(L<=20 && W<=20 && H<=20 && L>=1 && H<=50)
        {
            printf("Case %d: good\n", T);
        }
        else
        {
            printf("Case %d: bad\n", T);
        }
        T++;
    }
}
