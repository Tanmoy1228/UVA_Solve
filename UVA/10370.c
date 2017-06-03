#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,k,a[1000];
        float c=0,j,m=0,av;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            c=c+a[i];
        }
        j=c/n;
        for(k=0;k<n;k++)
        {
            if(a[k]>j)
            {
                m++;
            }
        }
        av=(100*m)/n;
        printf("%0.3f%%\n",av);
    }
    return 0;
}
