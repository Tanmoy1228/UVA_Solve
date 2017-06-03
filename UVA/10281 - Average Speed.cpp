#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[100];
    int hour,minute,second,prehour,preminute,presecond,a,b,h,m,s;
    int i,l;
    double pretime,totaltime,total,time,speed,prespeed;
    total=0.0;
    speed=0.0;
    prehour=0;
    preminute=0;
    presecond=0;
    pretime=0;
    prespeed=0;
    while(gets(str))
    {
       // gets(str);
        time=0.0;
        l=strlen(str);
        if(l<=0)
            break;
        if(l>8)
        {
            sscanf(str,"%d:%d:%d %lf",&hour,&minute,&second,&speed);
            time=hour*3600+minute*60+second;
            totaltime=time-pretime;
            pretime=time;
            totaltime=totaltime/3600;
            total=total+(prespeed*totaltime);
            prespeed=speed;
        }
        else
        {
            sscanf(str,"%d:%d:%d",&hour,&minute,&second);
            time=hour*3600+minute*60+second;
            totaltime=time-pretime;
            pretime=time;
            totaltime=totaltime/3600;
            total=total+(prespeed*totaltime);
            printf("%d%d:%d%d:%d%d %0.2lf km\n",hour/10,hour%10,minute/10,minute%10,second/10,second%10,total);
        }
    }
    return 0;
}
