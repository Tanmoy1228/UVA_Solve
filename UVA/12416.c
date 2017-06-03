#include<stdio.h>
#include<string.h>
char s[1000000];
long long int a[1000000];
int main()
{
    while(gets(s))
    {
        long long int l,i,j=0,k=0,m,n,b,c=0;
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]==' ')
            {
                j=j+1;
                continue;
            }
            else if(s[i-1]==' ')
            {
                a[k]=j;
                k++;
            }
            j=0;
        }
        m=a[0];
        for(i=1;i<k;i++)
        {
            if(m<a[i])
            {
                m=a[i];
            }
        }
        while(m>1)
        {
            n=m%2;
            b=m/2;
            m=b+n;
            c++;
        }
        printf("%lld\n",c);
    }
    return 0;
}
