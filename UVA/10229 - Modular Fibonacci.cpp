#include<bits/stdc++.h>
using namespace std;
long long int mod;

struct matrix
{
    long long int v[5][5];
    long long int row, col; // number of row and column
};

matrix multiply(matrix a, matrix b)
{
    matrix r;
    long long int i,j,k,sum;
    r.row = a.row;
    r.col = b.col;
    for (i = 0; i < r.row; i++)
    {
        for (j = 0; j < r.col; j++)
        {
            sum = 0;
            for (k = 0; k < a.col;  k++)
            {
                sum += a.v[i][k] * b.v[k][j];
                sum %= mod;
            }
            r.v[i][j] = sum;
            //cout<<sum<<endl;
        }
    }
    return r;
}

matrix power(matrix mat, long long int p)
{
    //cout<<p<<endl;
    if (p == 1)
        return mat;
    if (p % 2 == 1)
        return multiply(mat, power(mat, p - 1));
    matrix ret = power(mat, p / 2);
    ret = multiply(ret, ret);
    return ret;
}

int main()
{
    long long int n,m,i,j,ans;
    double d;
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        matrix mat;
        mat.row = mat.col = 2;
        mat.v[0][0] = mat.v[0][1] = mat.v[1][0] = 1;
        mat.v[1][1] = 0;
        d=pow(2,m);
        mod = ceil(d);
        //cout<<mod<<endl<<endl;
        if(m==0)
            cout << "0" << endl;
        else if (n < 3)
        {
            if (n == 0)
                cout << "0" << endl;
            if (n == 1)
                cout << "1" << endl;
            if (n == 2)
                cout << "1"<< endl;
        }
        else
        {
            mat = power(mat, n - 2);
            ans =mat.v[0][0]+mat.v[0][1];
            ans %= mod;
            cout << ans << endl;
        }
    }
    return 0;
}
