#include<bits/stdc++.h>
using namespace std;
long long int mod;
struct matrix
{
    long long int v[45][45];
    long long int row,col;
};
matrix I,A;

matrix add(matrix a, matrix b)
{
    matrix ret;
    long long int i,j,k,sum;
    ret.row=a.row;
    ret.col=a.col;
    for(i=0; i<ret.row; i++)
    {
        for(j=0; j<ret.col; j++)
        {
            sum=((a.v[i][j]%mod)+(b.v[i][j]%mod))%mod;
            ret.v[i][j]=sum;
        }
    }
    return ret;
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
                sum=(sum+((a.v[i][k]%mod)*(b.v[k][j]%mod))%mod)%mod;
            }
            ret.v[i][j]=sum;
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

matrix fun(long long int p)
{
    matrix ret;
    if(p==1)
        return I;
    if(p==2)
        return add(I,A);
    if(p==3)
        return add(I,add(A,power(A,2)));
    ret=multiply(add(I,power(A,p/2)),fun(p/2));
    if(p%2==1)
        ret=add(ret,power(A,p-1));
    return ret;
}
int main()
{
    long long int t,T,n,k,m,i,j,a,b,c;
    double d;
    matrix mat,ans,ans1;
    while(scanf("%lld %lld",&n,&k))
    {
        if(n==0)
            break;
        mat.row=n;
        mat.col=n;
        ans.col=n;
        ans.row=n;
        A.row=n;
        A.col=n;
        I.col=n;
        I.row=n;
        mod=10;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%lld",&mat.v[i][j]);
                ans.v[i][j]=0;
                A.v[i][j]=mat.v[i][j];
                I.v[i][j]=0;
            }
        }
        for(i=0; i<n; i++)
            I.v[i][i]=1;
        ans=fun(k+1);
        for(i=0; i<n; i++)
            I.v[i][i]=-1;
        ans=add(ans,I);
        //for(i=1; i<=k; i++)
       // {
            //ans1=power(mat,i);
            //ans=add(ans,ans1);

//            for(c=0; c<n; c++)
//            {
//                for(j=0; j<n-1; j++)
//                    printf("%lld ",ans.v[c][j]);
//                printf("%lld\n",ans.v[c][j]);
//            }
//            cout<<endl;
//            for(c=0; c<n; c++)
//            {
//                for(j=0; j<n-1; j++)
//                    printf("%lld ",ans1.v[c][j]);
//                printf("%lld\n",ans1.v[c][j]);
//            }
//            cout<<endl<<endl;
        //}
        for(i=0; i<n; i++)
        {
            for(j=0; j<n-1; j++)
                printf("%lld ",ans.v[i][j]);
            printf("%lld\n",ans.v[i][j]);
        }
        printf("\n");
    }
    return 0;
}

