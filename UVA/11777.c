#include<stdio.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        int t1,t2,f,a,c1,c2,c3,m1,m2;
        float av,total;
        scanf("%d %d %d %d %d %d %d",&t1,&t2,&f,&a,&c1,&c2,&c3);
        if(c1>=c2)
        {
            m1=c1;
            m2=c2;
        }
        else
        {
            m1=c2;
            m2=c1;
        }
        if(c3>=m2)
        {
            av=1.0*(c3+m1)/2;
        }
        else
        {
            av=1.0*(m1+m2)/2;
        }
        total=t1+t2+f+a+av;
        printf("Case %d: ",t);
        if(total>=90)
        {
            printf("A");
        }
        else if(total>=80)
        {
            printf("B");
        }
        else if(total>=70)
        {
            printf("C");
        }
        else if(total>=60)
        {
            printf("D");
        }
        else if(total<60)
        {
            printf("F");
        }
        printf("\n");
        t++;
    }
    return 0;
}
