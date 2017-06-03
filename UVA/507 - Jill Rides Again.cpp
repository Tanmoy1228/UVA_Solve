#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,start,finish,maxi,a,i,t,T,arr[20009],fst;
    scanf("%lld",&T);
    for(t=1;t<=T; t++)
    {
        scanf("%lld",&n);
        for(i=1; i<=n-1; i++)
            scanf("%lld",&arr[i]);
        maxi=0;
        a=0;
        fst = 1;
        finish = -1;
        for(i=1; i<=n-1; i++)
        {
            a+=arr[i];
            if(a<0)
            {
                a=0;
                fst=i+1;
            }
            else if(a>=maxi && (a!=0 || finish!=-1))
            {
                if(a==maxi && fst>finish)
                    continue;
                maxi=a;
                start=fst;
                finish=i;
            }
        }
        if(finish==-1)
            printf("Route %lld has no nice parts\n",t);
        else
            printf("The nicest part of route %lld is between stops %lld and %lld\n",t,start,finish+1);
    }

    return 0;
}
