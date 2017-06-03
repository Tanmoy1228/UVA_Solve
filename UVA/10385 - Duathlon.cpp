#include<bits/stdc++.h>
using namespace std;
long long int n,i;
double dis,run[30],cycle[30];
double timing(double p)
{
    double sum,a=9999999999;
    for(i=1;i<n;i++)
    {
        sum=p/run[i]+(dis-p)/cycle[i];
        a=min(a,sum);
    }
    sum=p/run[i]+(dis-p)/cycle[i];
    return a-sum;
}

void ternary_search()
{
    double left,right,mid1,mid2,a,b,ans;
    left=0;
    right=dis;
    while(fabs(left-right)>=0.00001)
    {
        mid1=(2*left+right)/3;
        mid2=(left+2*right)/3;
        a=timing(mid1);
        b=timing(mid2);
        if(a>=b)
        {
            right=mid2;
        }
        else
        {
            left=mid1;
        }
    }
    ans=timing(right)*60*60;
    if(ans<0)
        printf("The cheater cannot win.\n");
    else
        printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n", ans, right, dis-right);
}


int main()
{
    while(scanf("%lf",&dis)!=EOF)
    {
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lf %lf",&run[i],&cycle[i]);
        }
        ternary_search();
    }

    return 0;
}
