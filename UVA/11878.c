#include<stdio.h>
#include<string.h>
int main()
{
    char s[100],c[100];
    int a,b,l,i,x,y;
    while(scanf("%d%c%d=%s",&a,&c[0],&b,s)!=EOF)
    {
        if(a==0 && b==0)
        {
            break;
        }
        if(s[0]<'?')
        {
            continue;
        }
        else
        {
            y=0;
            l=strlen(s);
            for(i=0;i<l;i++)
            {
                x=s[i]-'0';
                y=y*10;
                y=x+y;
            }
            if(c[0]=='+')
            {
                if(y==a+b)
                {
                    continue;
                }
                else
                {
                    printf("%d\n",a+b);
                }
            }
            else if(c[0]=='-')
            {
                if(y==a-b)
                {
                    continue;
                }
                else
                {
                    printf("%d\n",a-b);
                }
            }
        }
    }
    return 0;
}
