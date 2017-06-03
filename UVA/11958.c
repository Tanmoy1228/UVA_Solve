#include<stdio.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        int n,h,m,a[100],b[100],v[100],c[100],x,y,z,i,j,min;
        scanf("%d %d:%d",&n,&h,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d:%d %d",&a[i],&b[i],&v[i]);
        }
        for(i=0;i<n;i++)
        {
            if(m>b[i])
            {
                b[i]=b[i]+60;
                a[i]=a[i]-1;
            }
            y=b[i]-m;
            if(h>a[i])
            {
                a[i]=a[i]+24;
            }
            x=a[i]-h;
            z=x*60+y+v[i];
            c[i]=z;
        }
        min=c[0];
        for(i=1;i<n;i++)
        {
            if(min>c[i])
            {
                min=c[i];
            }
        }
        printf("Case %d: %d\n",t,min);
        t++;
    }
    return 0;
}
