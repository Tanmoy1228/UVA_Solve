#include<bits/stdc++.h>
using namespace std;
long long int mod;
struct matrix
{
    long long int v[5][5];
    long long int row,col;
};

matrix multiply(matrix a, matrix b)
{
    matrix ret;
    long long int i,j,k,sum;
    ret.row=a.row;
    ret.col=b.col;
    for(i=0; i<ret.row; i++)
    {
        for(j=0; j<ret.col; j++)
        {
            sum=0;
            for(k=0; k<a.col; k++)
            {
                sum=(sum+(a.v[i][k]*b.v[k][j])%mod)%mod;
            }
            ret.v[i][j]=sum%mod;
        }
    }
    return ret;
}
matrix power(matrix mat, long long int p)
{
    if(p==1)
        return mat;
    else if(p%2==1)
        return multiply(mat,power(mat,p-1));
    else
    {
        matrix ret;
        ret=power(mat,p/2);
        return multiply(ret,ret);
    }
}
int main()
{
    long long int t,T,n,m,i,j,a,b,c,ans;
    double d;
    matrix mat;
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&n,&m);
        d=pow(10,m);
        mod=ceil(d);
        //mod=m;
        mat.row=2;
        mat.col=2;
        mat.v[0][0]=mat.v[0][1]=mat.v[1][0]=1;
        mat.v[1][1]=0;
        a=a%mod;
        b=b%mod;
        c=(a+b)%mod;
        //cout<<mod<<endl;
        if(n==0)
            printf("%lld\n",a);
        else if(n==1)
            printf("%lld\n",b);
        else if(n==2)
            printf("%lld\n",c);
        else
        {
            mat=power(mat,n-2);
            ans=(c*mat.v[0][0])%mod+(b*mat.v[0][1])%mod;
            ans%=mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
