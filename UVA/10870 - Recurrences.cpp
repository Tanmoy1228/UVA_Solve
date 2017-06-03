#include<bits/stdc++.h>
using namespace std;
long long int mod,A[25],B[25];
struct matrix
{
    long long int row,col;
    long long int v[25][25];
};
matrix set_value(long long int row, long long int col)
{
    long long int i,j;
    matrix mat;
    mat.row=row;
    mat.col=col;
    for(i=0; i<col; i++)
        mat.v[0][i]=A[i];
    for(i=1; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(i-1==j)
                mat.v[i][j]=1;
            else
                mat.v[i][j]=0;
        }
    }
    return mat;
}
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
    long long int d,n,i,j,sum;
    while(scanf("%lld %lld %lld",&d,&n,&mod) && d && n && mod)
    {
        matrix mat;
        for(i=0; i<d; i++)
        {
            scanf("%lld",&A[i]);
            A[i]=A[i]%mod;
        }
        for(i=d-1; i>=0; i--)
        {
            scanf("%lld",&B[i]);
            B[i]=B[i]%mod;
        }
        mat=set_value(d+1,d);
        sum=0;
//        for(i=0; i<=d; i++)
//        {
//            for(j=0; j<d; j++)
//                cout<<mat.v[i][j]<<" ";
//            cout<<endl;
//        }
        if(n<=d)
            printf("%lld\n",B[n-1]);
        else
        {
            mat=power(mat,n-d);
            for(i=0,j=d-1; i<d; i++,j--)
                sum=(((mat.v[0][i]*B[i])%mod)+sum)%mod;
            printf("%lld\n",sum);
        }
    }
}
