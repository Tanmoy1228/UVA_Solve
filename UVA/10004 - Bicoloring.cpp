#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n1,n2,g;
    while(scanf("%d",&n1)!=EOF)
    {
        if(n1==0)
        {
            break;
        }
        scanf("%d",&n2);
        int i,j,k,a,b,c=0,x=0,y=0,l,w,q,z;
        int f,g,h,o=2,p=3,colour[1000]= {0};
        map<int,int>m;
        vector<int>v[1000];
        vector<int>::iterator it;
        for(i=0; i<n2; i++)
        {
            scanf("%d %d",&a,&b);

            if(m.count(a)==0)
            {
                m[a]=c;
                c++;
            }
            if(m.count(b)==0)
            {
                m[b]=c;
                c++;
            }
            v[m[a]].push_back(m[b]);
            v[m[b]].push_back(m[a]);
        }
        l=m.size();
        for(i=0; i<l; i++)
        {
            if(colour[i]!=0)
            {
                o=colour[i];
                if(o==2)
                {
                    p=3;
                }
                else
                {
                    p=2;
                }
            }
            colour[i]=o;
            f=v[i].size();
            for(j=0; j<f; j++)
            {
                g=v[i][j];
                if(colour[g]==o && i!=g)
                {
                    printf("NOT BICOLORABLE.\n");
                    y=2;
                    break;
                }
                colour[g]=p;
            }
            if(y==2)
            {
                break;
            }
        }
        if(y==2)
        {
            continue;
        }
        printf("BICOLORABLE.\n");
    }
    return 0;

}

