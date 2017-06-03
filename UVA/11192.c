#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int l,i,j,k=0,x,m;
        char s[1000],a[1000];
        scanf("%s",s);
        l=strlen(s);
        if(n==0)
        {
            break;
        }
        m=l/n;
        for(i=1;i<=n;i++)
        {
            for(j=(i*m)-1;j>=(i-1)*m;j--)
            {
                a[k]=s[j];
                k++;
            }
        }
        for(x=0;x<l;x++)
        {
            printf("%c",a[x]);
        }
        printf("\n");
    }
}

