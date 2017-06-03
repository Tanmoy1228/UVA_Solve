#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        long long int i,j=0,k=0,l=0,m=0,o=0,a,b,c=1,s,q[1000];
        printf("%3d! =",n);
        for(i=n;i>0;i--)
        {
            a=i*c;
            while(a%2==0)
            {
                a=a/2;
                k++;
            }
            while(a%3==0)
            {
                a=a/3;
                l++;
            }
            while(a%5==0)
            {
                a=a/5;
                m++;
            }
            while(a%7==0)
            {
                a=a/7;
                o++;
            }
            c=a;
        }
        printf(" %lld ",a);
        q[j]=k;
        j++;
        q[j]=l;
        j++;
        q[j]=m;
        j++;
        q[j]=o;
        j++;
        s=sqrt(n);
        for(i=11;i<=s;i=i+2)
        {
            k=0;
            while(a%i==0)
            {
                a=a/i;
                k++;
            }
            q[j]=k;
            j++;
        }
        for(b=0;b<j;b++)
        {
            printf(" %lld",q[b]);
        }
        printf("\n");
    }
    return 0;
}
