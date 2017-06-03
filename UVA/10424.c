#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100];
    while((gets(a) && gets(b))!=EOF)
    {
        int i,j=0,x,y,c=0,d,e,f=0;
        double z;
        x=strlen(a);
        y=strlen(b);
        for(i=0;i<x;i++)
        {
            if(a[i]>64 && a[i]<91)
            {
                c=c+a[i]-64;
            }
            else if(a[i]>96 && a[i]<123)
            {
                c=c+a[i]-96;
            }
        }
        d=c;
        c=0;
        while(d>0)
        {
            c=c+d%10;
            d=d/10;
        }
        if(c>9)
        {
            d=c;
            c=0;
            while(d>0)
            {
                c=c+d%10;
                d=d/10;
            }
        }
        for(i=0;i<y;i++)
        {
            if(b[i]>64 && b[i]<91)
            {
                j=j+b[i]-64;
            }
            else if(b[i]>96 && b[i]<123)
            {
                j=j+b[i]-96;
            }
        }
        d=j;
        j=0;
        while(d>0)
        {
            j=j+d%10;
            d=d/10;
        }
        if(j>9)
        {
            f=j;
            j=0;
            while(f>0)
            {
                j=j+f%10;
                f=f/10;
            }
        }
        if(c>=j)
        {
            z=((1.0*j)/(1.0*c))*100.0;
        }
        else if(c<j)
        {
            z=((1.0*c)/(1.0*j))*100.0;
        }
        printf("%0.2lf %%\n",z);
    }
    return 0;
}
