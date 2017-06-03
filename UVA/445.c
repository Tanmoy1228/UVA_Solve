#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],p=' ';
    while(scanf("%s",s)!=EOF)
    {
        int i,j,l,x,k;
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]>='1' && s[i]<='9')
            {
                j=s[i]-'0';
                x=i+1;
                while(s[x]>='0' && s[x]<='9')
                {
                    j=j+s[x]-'0';
                    x++;
                }
                for(k=0;k<j;k++)
                {
                    if(s[x]=='b')
                    {
                        printf("%c",p);
                    }
                    else if(s[x]=='!')
                    {
                        printf("\n");
                    }
                    else
                    {
                        printf("%c",s[x]);
                    }
                }
                i=x;
            }
            else if(s[i]=='!')
            {
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
