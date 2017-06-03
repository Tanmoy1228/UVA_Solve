#include<stdio.h>
#include<string.h>
int main()
{
    int t=1;
    char s[15];
    while(scanf("%s",s))
    {
        unsigned long long l,i,j=0,k,w=0,x,y,f=0,g=0,z=0,a=0,b,c,d,e;
        l=strlen(s);
        printf("%4d. ",t);
        if(l>=8)
        {
            for(j=0;j<l-7;j++)
            {
                x=s[j]-'0';
                w=z*10;
                z=w+x;
            }
            f=z;
            if(z>=10000000)
            {
                b=z/10000000;
                z=z%10000000;
                printf("%llu kuti",b);
                if(z>0)
                {
                    printf(" ");
                }
            }
            if(z>=100000)
            {
                c=z/100000;
                z=z%100000;
                printf("%llu lakh",c);
                if(z>0)
                {
                    printf(" ");
                }
            }
            if(z>=1000)
            {
                d=z/1000;
                z=z%1000;
                printf("%llu hajar",d);
                if(z>0)
                {
                    printf(" ");
                }
            }
            if(z>=100)
            {
                e=z/100;
                z=z%100;
                printf("%llu shata",e);
                if(z>0)
                {
                    printf(" ");
                }
            }
            if(z>0)
            {
                printf("%llu",z);
            }
            if(f>0)
            {
                printf(" kuti");
            }
        }
        if(l>0)
        {
            for(i=j;i<l;i++)
            {
                if((s[i]-'0')<=9 && (s[i]-'0')>=0)
                {
                    x=s[i]-'0';
                }
                else
                {
                    x=0;
                }
                y=a*10;
                a=y+x;
            }
            g=a;
            if(f>0 && a>0)
            {
                printf(" ");
            }
            if(a>=100000)
            {
                c=a/100000;
                a=a%100000;
                printf("%llu lakh",c);
                if(a>0)
                {
                    printf(" ");
                }
            }
            if(a>=1000)
            {
                d=a/1000;
                a=a%1000;
                printf("%llu hajar",d);
                if(a>0)
                {
                    printf(" ");
                }
            }
            if(a>=100)
            {
                e=a/100;
                a=a%100;
                printf("%llu shata",e);
                if(a>0)
                {
                    printf(" ");
                }
            }
            if(a>0)
            {
                printf("%llu",a);
            }
        }
        if(f==0 && g==0)
        {
            printf("0");
        }
        printf("\n");
        t++;
    }
    return 0;
}
