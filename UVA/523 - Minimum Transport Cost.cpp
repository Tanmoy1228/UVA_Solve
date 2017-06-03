#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
long long int mat[10000][10000];
long long int vat[10000];
long long int next[10000][10000];
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int t,T,co=0;
    char test[10];
    cin>>T;
    getchar();
    getchar();
    //gets(test);
    //sscanf(test,"%d",&T);
    //while(getchar() != '\n');
    //while(getchar() != '\n');
    //getchar();

    for(t=1; t<=T; t++)
    {
        char s[100000],fs_ls[10];
        long long int i,j,k,l,counter=1,a=0,element,first,last,start_des[5];

        //scanf("%c",blank);
        //getchar();
        gets(s);
        l=strlen(s);
        if(!l)
        {
            t--;
            continue;
        }
//        for(i=1; i<l; i++)
//        {
//            for(j=1; j<l; j++)
//            {
//                mat[i][j]=99999999;
//            }
//        }
//        for(j=1; j<10000; j++)
//        {
//            vat[j]=0;
//            next[i][j]=j;
//        }


        for(i=0; i<l; i++)
        {
            if(s[i]=='-')
            {
                a=0;
                mat[1][counter]=99999999;
                counter++;
                i=i+2;
                continue;
            }
            if(s[i]==' ')
            {
                mat[1][counter]=a;
                a=0;
                counter++;
                continue;
            }
            k=s[i]-'0';
            a=a*10;
            a=a+k;
        }
        mat[1][counter]=a;
        for(i=1; i<=counter; i++)
        {
            for(j=1; j<=counter; j++)
            {
                next[i][j]=j;
            }
            vat[i]=0;
        }
        for(i=2; i<=counter; i++)
        {
            for(j=1; j<=counter; j++)
            {
                scanf("%lld",&element);
                if(element==-1)
                {
                    mat[i][j]=99999999;
                    continue;
                }
                mat[i][j]=element;
            }
        }
        for(j=1; j<=counter; j++)
        {
            scanf("%lld",&vat[j]);
        }

        for(k=1; k<=counter; k++)
        {
            for(i=1; i<=counter; i++)
            {
                for(j=1; j<=counter; j++)
                {
                    if(mat[i][j]>mat[i][k]+mat[k][j]+vat[k])
                    {
                        mat[i][j]=mat[i][k]+mat[k][j]+vat[k];
                        next[i][j]=next[i][k];
                    }

                }

            }
        }
        getchar();
        //while(scanf("%lld %lld",&first,&last)==2)
        while(gets(fs_ls))
        {

            l=strlen(fs_ls);
            //cout<<l<<endl;
            if(!l)
            {
                break;
            }
            a=0;
            counter=1;
            for(i=0; i<l; i++)
            {
                if(s[i]==' ')
                {
                    start_des[counter]=a;

                    counter++;
                    a=0;

                    continue;
                }
                k=fs_ls[i]-'0';

                a=a*10;
                a=a+k;
            }
            start_des[counter]=a;
            first=start_des[1];
            last=start_des[2];
            printf("From %lld to %lld :\n",first,last);
            printf("Path: ");
            i=first;
            j=last;

            printf("%lld",i);

            while(i!=j)
            {
                if(i==j)
                {
                    printf("%lld",j);
                    break;
                }
                printf("-->%lld",next[i][j]);
                i=next[i][j];

                co++;
                if(co>200)
                {
                    break;
                }
            }
            //getchar();
//            if(getchar()=='\n')
//            {
//                break;
//            }

            printf("\nTotal cost : %lld\n\n",mat[first][last]);

//        for(i=1; i<=counter; i++)
//        {
//            for(j=1; j<=counter; j++)
//            {
//                printf("%lld %lld %lld %lld \n",i,j,next[i][j],mat[i][j]);
//            }
//            cout<<endl;
//        }
        }
        //cout<<endl;
        //getchar();
//        getchar();
    }
    return 0;
}

