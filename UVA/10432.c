#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main()
{
    int r,s;
    while(scanf("%d %d",&r,&s)!=EOF)
    {
        double x,y;
        if(r<=0 || s<=0)
        {
            break;
        }
        y=sin((PI)/s);
        x=(r*r*s*y);
        printf("%0.3lf\n",x);
    }
    return 0;
}
