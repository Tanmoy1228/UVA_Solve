#include<stdio.h>
int main()
{
    long long int a,b,c,d,L,i,j,m;
    while(scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&L)!=EOF)
    {
        if(a==0 && b==0 && c==0 && d==0 && L==0)
        {
            break;
        }
        else
        {

            m=0;
            for(i=0;i<=L;i++)
            {
                j=(a*i*i)+(b*i)+c;
                if(j%d==0)
                {
                    m++;
                }
            }
            printf("%lld\n",m);
        }
    }
    return 0;
}
