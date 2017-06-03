#include<stdio.h>
#include<string.h>
int main()
{
    char s[10000];
    while(gets(s))
    {
        int i=0,l,b=0,j;
        l=strlen(s);
        for(i=b;i<l;i++)
        {
            if(s[i+1]==' ')
            {
                for(j=i;j>=b;j--)
                {
                    printf("%c",s[j]);
                }
                b=i+2;
                printf(" ");
            }
            else if(s[i+1]=='\0')
            {
                for(j=i;j>=b;j--)
                {
                    printf("%c",s[j]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
