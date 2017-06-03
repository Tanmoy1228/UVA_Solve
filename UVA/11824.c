#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,i,j,k,l=0,c=0,a[1000],b[1000];
        for(i=0;;i++)
        {
            scanf("%lld",&a[i]);
            if(a[i]==0)
            {
                break;
            }
        }
        for(j=0;j<i-1;j++)
        {
            for(k=j+1;k<i;k++)
            {
                if(a[j]<a[k])
                {
                    n=a[j];
                    a[j]=a[k];
                    a[k]=n;
                }
            }
        }
        c=2*a[0];
        printf("%lld\n",c);
        for(j=1;j<i;j++)
        {
            c = c + 2 * (pow(a[j],j+1));
            l=2 * pow(a[j],j+1);
            printf("%lld\n",l);
        }
        if(c>5000000)
        {
            printf("Too expensive");
        }
        else
        {
            printf("%lld\n",c);
        }
    }
    return 0;
}
