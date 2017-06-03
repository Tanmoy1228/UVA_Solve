#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    double n1,n2,d,p,p1,q,i,j,ans;

    while(scanf("%lf %lf %lf %lf",&n1,&n2,&p,&d) && n1 && n2 && p && d)
    {
        n1=ceil(n1/d);
        n2=ceil(n2/d);

        if(p==3.00)
        {
            p1=(n1/(n1+n2));
            p1=p1*100.0;
            printf("%0.1lf\n",p1);
            continue;
        }
        q=6.0-p;
        p1=1.0-powl((q/p),n1);
        p1=p1/(1.0-powl((q/p),n1+n2));
        p1=p1*100.0;
        printf("%0.1lf\n",p1);
    }
    return 0;
}

