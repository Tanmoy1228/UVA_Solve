#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long c;
int num[500005],snum[500005];
void Merge(int low,int mid,int high)
{
    int h,i,j,k;
    h=i=low;
    j=mid+1;
    while(h<=mid&&j<=high)
    {
        if(num[h]<=num[j])
        {
            snum[i++]=num[h++];
            c+=i-h;
        }
        else
        {
            snum[i++]=num[j++];
        }
    }
    if(h>mid)
        for(k=j; k<=high; k++)
            snum[i++]=num[k];
    else
        for(k=h; k<=mid; k++)
            snum[i++]=num[k],c+=i-k-1;
    for(k=low; k<=high; k++)
        num[k]=snum[k];
}
void MergeSort(int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(low,mid);
        MergeSort(mid+1,high);
        Merge(low,mid,high);
    }
}
int main()
{
    int n,i;
    //freopen("in.txt","r",stdin);

    while(scanf("%d",&n) && n)
    {
        for(i=0; i<n; i++)
            scanf("%d",&num[i]);
        c=0;
        MergeSort(0,n-1);

        printf("%llu\n",c);
    }
    return 0;
}
