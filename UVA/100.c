#include<stdio.h>

int main()
{
    long long int n,m,i,k=0,b,maxi,l,a,c,counter;;
    while(scanf("%lld %lld",&n,&m)==2)
    {
        if(n>m)
        {
            b=n;
            a=m;
        }
        else
        {
            a=n;
            b=m;
        }
        maxi=0;
        for(i=a;i<=b;i++)
        {
            c=i;
            counter=1;
            while(c>1)
            {
                counter++;
                if(c%2==0)
                {
                    c=c/2;
                }
                else
                {
                    c=3*c+1;
                }
            }
            if(maxi<counter)
            {
                maxi=counter;
            }
        }
        printf("%lld %lld %lld\n",n,m,maxi);
    }
    return 0;
}
