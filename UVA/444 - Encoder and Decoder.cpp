#include<bits/stdc++.h>


using namespace std;

int main()
{
    char res[10000];
    string str;
    while(getline (cin,str))
    {
        //getchar();
        int len=str.size(),j=0;
        //cout<<len<<endl;
        if(len==0)
            printf("\n");
        else if(str[0]>='0'&&str[0]<='9')
        {
            for(int i=len-1; i>=0; )
            {
                int temp=((str[i]-'0')*10)+(str[i-1]-'0');
                if(temp>=32)
                {
                    res[j++]=temp;
                    i-=2;
                }
                else if(temp<=12)
                {
                    temp=temp*10+(str[i-2]-'0');
                    res[j++]=temp;
                    i-=3;
                }
            }
            for(int i=0; i<j; i++) printf("%c",res[i]);
            printf("\n");
        }
        else
        {
            for(int i=len-1; i>=0; i--)
            {
                int tempa=str[i];
                while(tempa)
                {
                    res[j++]=(tempa%10)+'0';
                    tempa/=10;
                }
            }
            for(int i=0; i<j; i++) printf("%c",res[i]);
            printf("\n");
        }
    }
    return 0;
}
