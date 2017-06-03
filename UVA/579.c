#include<stdio.h>
#include<stdlib.h>
int main()
{
    double hand1,hand2,angle;
    int hour,minute;
    while(scanf("%d:%d",&hour,&minute)==2)
    {
        if(hour==0 && minute==0)
            break;
        hand1=hour*60+minute;
        hand1=hand1/2;
        hand2=minute*6;
        if(hand1>hand2)
            angle=hand1-hand2;
        else
            angle=hand2-hand1;
        if(angle>180)
            angle=360-angle;
        printf("%0.3lf\n",angle);
    }
    return 0;
}
