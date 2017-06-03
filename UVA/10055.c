#include<stdio.h>
int main()
{
    long int h,o,ans;
    while(scanf("%ld  %ld", &h, &o)!=EOF)
    {
        if(h>o)
        {
            ans = h-o;
        }
        else
        {
            ans = o-h;
        }
        printf("%ld\n",ans);
    }
    return 0;
}
