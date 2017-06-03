#include<bits/stdc++.h>
using namespace std;
long long int A[10000009],L[10000009],I[10000009],B[10000009];
int main()
{
    long long int t,T,n,i,j,m,l,h,lis,top;
    string c;
    //freopen("in.txt","r",stdin);
    scanf("%lld",&T);
    getchar();
    getchar();
    for(t=1;t<=T;t++)
    {
        i=1;
        while(getline(cin,c))
        {
            if(c.size()==0)
                break;
            l=c.size();
            n=0;
            j=0;
            while(l>j)
            {
                n=(n*10)+c[j]-'0';
                j++;
            }
            A[i]=n;
            //cout<<c[0]-'0'<<endl;
            i++;
        }
        //cout<<i<<endl;
        n=i-1;
        lis=0;
        I[0]=-999999999;
        for(i=1;i<=n;i++)
            I[i]=999999999;
        for(i=1;i<=n;i++)
        {
            l=0;
            h=lis;
            while(l<=h)
            {
                m=(l+h)/2;
                if(I[m]<A[i])
                    l=m+1;
                else
                    h=m-1;
            }
            I[l]=A[i];
            B[i]=l;
            if(l>lis)
                lis=l;
        }
        printf("Max hits: %lld\n",lis);
        for(i=1,j=1;i<=n;i++)
            if(B[i]>B[j])
                j=i;
        top=B[j];
        L[top]=A[j];
        for(i=j-1;i>=0;i--)
        {
            if(A[i]<A[j] && B[i]+1==B[j])
            {
                top--;
                L[top]=A[i];
                j=i;
            }
        }
        for(i=1;i<=lis;i++)
            printf("%lld\n",L[i]);
        //printf("%lld",L[i]);
        if(t!=T)
            printf("\n");
    }
    return 0;
}
