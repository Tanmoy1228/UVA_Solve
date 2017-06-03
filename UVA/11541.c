#include<stdio.h>
#include<string.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        int l,i,j,k,a,c;
        char s[300];
        scanf("%s",s);
        l=strlen(s);
        printf("Case %d: ",t);
        for(i=0;i<l;i=i+1)
        {
            c=0;
            for(k=i+1;k<l;k++)
            {
                if(s[k]>='0' && s[k]<='9')
                {
                    a=s[k]-'0';
                    c=c*10;
                    c=c+a;
                }
                else
                {
                    break;
                }
            }
            for(j=0;j<c;j++)
            {
                printf("%c",s[i]);
            }
            i=k-1;
        }
        printf("\n");
        t++;
    }
    return 0;
}
