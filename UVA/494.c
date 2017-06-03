#include<stdio.h>
#include<string.h>
int main()
{
    char s[10000];
    while(gets(s))
    {
        int i,l,c=0,y=0;
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            {
                if(y==1)
                {
                    continue;
                }
                else
                {
                    c++;
                    y=1;
                }
            }
            else
            {
                y=0;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
