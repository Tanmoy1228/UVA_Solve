#include<stdio.h>
#include<string.h>
int main()
{
    char s[1002];
    while(scanf("%s",s))
    {
        long long int l,i,a,g=0,d=0;
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            a=s[i]-'0';
            d=d*10;
            d=d+a;
            if(d<11 && i<l-1)
            {
                i++;
                a=s[i]-'0';
                d=d*10;
                d=d+a;
            }
            if(d>10)
            {
                g=d/11;
                d=d%11;
            }
        }
        if(g==0 && d==0)
        {
            break;
        }
        else if(d==0 && g>0)
        {
            printf("%s is a multiple of 11.\n",s);
        }
        else
        {
            printf("%s is not a multiple of 11.\n",s);
        }
    }
    return 0;
}

