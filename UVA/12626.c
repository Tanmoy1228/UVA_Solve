#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    char s[1000];
    scanf("%d",&t);
    while(t--)
    {
        int l,j,a=0,m=0,r=0,g=0,i=0,t=0,c=0;
        scanf("%s",s);
        l=strlen(s);
        for(j=0;j<l;j++)
        {
            if(s[j]=='A')
            {
                a++;
            }
            else if(s[j]=='M')
            {
                m++;
            }
            else if(s[j]=='R')
            {
                r++;
            }
            else if(s[j]=='G')
            {
                g++;
            }
            else if(s[j]=='T')
            {
                t++;
            }
            else if(s[j]=='I')
            {
                i++;
            }
        }
        while(m>=1 && a>=3 && r>=2 && g>=1 && i>=1 && t>=1)
        {
            m--;
            g--;
            i--;
            t--;
            a=a-3;
            r=r-2;
            c++;
        }
        printf("%d\n",c);
    }
    return 0;
}
