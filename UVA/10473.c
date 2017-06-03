#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[1000],a[1000];
    while(scanf("%s",s))
    {
        int i=0,j,l,x,y=0,c=0;
        l=strlen(s);
        if(s[0]=='-')
        {
            break;
        }
        else if(s[0]=='0' && s[1]=='x')
        {
            for(i=2;i<l;i++)
            {
                if(s[i]=='A')
                {
                    x=10;
                }
                else if(s[i]=='B')
                {
                    x=11;
                }
                else if(s[i]=='C')
                {
                    x=12;
                }
                else if(s[i]=='D')
                {
                    x=13;
                }
                else if(s[i]=='E')
                {
                    x=14;
                }
                else if(s[i]=='F')
                {
                    x=15;
                }
                else
                {
                    x=s[i]-'0';
                }
                y=pow(16,(l-1-i));
                c=c+x*y;
            }
            printf("%d\n",c);
        }
        else
        {
            for(j=0;j<l;j++)
            {
                c=s[j]-'0';
                y=y*10;
                y=y+c;
            }
            if(y==0)
            {
                printf("0x0\n");
                continue;
            }
            while(y>0)
            {
                x=y%16;
                y=y/16;
                if(x==10)
                {
                    a[i]='A';
                    i++;
                }
                else if(x==11)
                {
                    a[i]='B';
                    i++;
                }
                else if(x==12)
                {
                    a[i]='C';
                    i++;
                }
                else if(x==13)
                {
                    a[i]='D';
                    i++;
                }
                else if(x==14)
                {
                    a[i]='E';
                    i++;
                }
                else if(x==15)
                {
                    a[i]='F';
                    i++;
                }
                else
                {
                    a[i]=x+'0';
                    i++;
                }
            }
            printf("0x");
           for(j=i-1;j>=0;j--)
           {
               printf("%c",a[j]);
           }
           printf("\n");
        }
    }
    return 0;
}
