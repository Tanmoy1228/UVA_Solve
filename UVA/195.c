#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[1000];
        int l,a,b,c,d;
        scanf("%s",s);
        l=strlen(s);
        for(a=0;a<l;a++)
        {
            for(b=0;b<l;b++)
            {
                for(c=0;c<l;c++)
                {
                    for(d=0;d<l;d++)
                    {
                        if(a!=b && a!=c && b!=d && b!=c && c!=d && d!=a)
                        {
                            printf("%c %c %c %c\n",s[a],s[b],s[c],s[d]);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
