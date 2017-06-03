#include<iostream>
#include<cstdio>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    char s1[10],s2[10];
    while(scanf("%s %s",&s1,&s2)!=EOF)
    {
        int a,b,c,d,i,j,k,l,w,x,y,z;
        queue<int>q1;
        queue<int>q2;
        int taken[10][10]={0};
        int dis[10][10]={0};
        x=s1[0]-'a'+1;
        y=s1[1]-'0';
        w=s2[0]-'a'+1;
        z=s2[1]-'0';
        c=x;
        d=y;
        q1.push(x);
        q2.push(y);
        dis[c][d]=0;
        if(c==w && d==z)
        {
            printf("To get from %s to %s takes 0 knight moves.\n",s1,s2);
            continue;
        }
        while(!q1.empty())
        {
            c=q1.front();
            d=q2.front();

            if(c==w && d==z)
            {
                printf("To get from %s to %s takes %d knight moves.\n",s1,s2,dis[w][z]);
                break;
            }
            if(taken[c][d]==1)
            {
                q1.pop();
                q2.pop();
                continue;
            }
            if(c>=1 && c<=8 && d>=1 && d<=8)
            {
                taken[c][d]=1;
                if(taken[c+2][d-1]!=1 && c+2>=1 && c+2<=8 && d-1>=1 && d-1<=8)
                {
                    q1.push(c+2);
                    q2.push(d-1);
                    dis[c+2][d-1]=dis[c][d]+1;
                }
                if(taken[c+2][d+1]!=1 && c+2>=1 && c+2<=8 && d+1>=1 && d+1<=8)
                {
                    q1.push(c+2);
                    q2.push(d+1);
                    dis[c+2][d+1]=dis[c][d]+1;
                }
                if(taken[c-2][d-1]!=1 && c-2>=1 && c-2<=8 && d-1>=1 && d-1<=8)
                {
                    q1.push(c-2);
                    q2.push(d-1);
                    dis[c-2][d-1]=dis[c][d]+1;
                }
                if(taken[c-2][d+1]!=1 && c-2>=1 && c-2<=8 && d+1>=1 && d+1<=8)
                {
                    q1.push(c-2);
                    q2.push(d+1);
                    dis[c-2][d+1]=dis[c][d]+1;
                }
                if(taken[c+1][d+2]!=1 && c+1>=1 && c+1<=8 && d+2>=1 && d+2<=8)
                {
                    q1.push(c+1);
                    q2.push(d+2);
                    dis[c+1][d+2]=dis[c][d]+1;
                }
                if(taken[c-1][d+2]!=1 && c-1>=1 && c-1<=8 && d+2>=1 && d+2<=8)
                {
                    q1.push(c-1);
                    q2.push(d+2);
                    dis[c-1][d+2]=dis[c][d]+1;
                }
                if(taken[c+1][d-2]!=1 && c+1>=1 && c+1<=8 && d-2>=1 && d-2<=8)
                {
                    q1.push(c+1);
                    q2.push(d-2);
                    dis[c+1][d-2]=dis[c][d]+1;
                }
                if(taken[c-1][d-2]!=1 && c-1>=1 && c-1<=8 && d-2>=1 && d-2<=8)
                {
                    q1.push(c-1);
                    q2.push(d-2);
                    dis[c-1][d-2]=dis[c][d]+1;
                }
            }

            q1.pop();
            q2.pop();
        }
    }
    return 0;
}

