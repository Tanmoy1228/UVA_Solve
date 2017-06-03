#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    int T;

    vector<string>dictionary;
    vector<int>connect_word[1000];

    map<string,int>m;
    map<string,int>::iterator mt;
    scanf("%d",&T);
    getchar();
    getchar();
    while(T--)
    {

        int counter=1;
        int length, ch_len, str_len, dic_size;
        int diff;
        int i,j;
        char dic[15],dic1[15];
        string s2,s3,s1,dic2;
        while(gets(dic))
        {
            if(strcmp(dic,"*")==0)
            {
                break;
            }
            if(counter==1)
            {
                m[dic]=counter;
                counter++;
                dictionary.push_back(dic);
                continue;
            }
            m[dic]=counter;
            counter++;
            dic_size=dictionary.size();
            ch_len=strlen(dic);
            for(i=0; i<dic_size; i++)
            {
                dic2=dictionary[i];
                str_len=dic2.size();

                diff=0;
                if(str_len==ch_len)
                {
                    for(j=0; j<ch_len; j++)
                    {
                        if(dic[j]!=dictionary[i][j])
                        {
                            diff++;
                        }
                    }
                    if(diff==1)
                    {
                        connect_word[m[dic2]].push_back(m[dic]);
                        connect_word[m[dic]].push_back(m[dic2]);
                    }
                }
            }
            dictionary.push_back(dic);
        }
//    for(mt=m.begin();mt!=m.end();++mt)
//    {
//        cout<<mt->first<<"\t"<<mt->second<<endl;
//    }
//    l=m.size();
//    for(i=1;i<=l;i++)
//    {
//        k=connect_word[i].size();
//        cout<<i<<"  ->  ";
//        for(j=0;j<k;j++)
//        {
//            cout<<connect_word[i][j]<<"   ";
//        }
//        cout<<endl;
//    }
        char word[100];
        while(gets(word))
        {
            length=strlen(word);
            if(length==0)
                break;
            char *pch;
            //string a, b;
            pch = strtok(word, " ");
            s2 = pch;
            pch = strtok (NULL, " ");
            s3 = pch;

//            for(i=0;i<length;i++)
//            {
//                if(word[i]==' ')
//                    break;
//                s2[i]=word[i];
//            }
//            int k=0;
//            for(j=i;j<length;j++,k++)
//            {
//                s2[k]=word[k];
//            }
            int dis[1000]= {0},visit[1000]= {0};
            int a,b,c;
            int d=0;
            a=m[s2];
            b=m[s3];
            queue<int>src;
            src.push(a);
            dis[a]=0;
            if(s2==s3)
            {
                cout<<s2<<" "<<s3<<" "<<dis[a]<<endl;
                continue;
            }

            //cout<<s2<<" "<<s3<<endl;
            while(!src.empty())
            {
                a=src.front();
                src.pop();
                if(visit[a]==1)
                {
                    continue;
                }
                visit[a]=1;
                length=connect_word[a].size();
                for(i=0; i<length; i++)
                {
                    c=connect_word[a][i];
                    if(visit[c]==1 || dis[c]>0)
                    {
                        continue;
                    }
                    src.push(c);
                    //cout<<c<<endl;
                    dis[c]=dis[a]+1;
                    if(c==b)
                    {
                        cout<<s2<<" "<<s3<<" "<<dis[b]<<endl;
                        d=1;
                        break;
                    }
                }
                if(d==1)
                {
                    break;
                }

            }
        }
        if(T!=0)
            cout<<endl;
        dictionary.clear();
        m.clear();
        for(i=0;i<=counter;i++)
        {
            connect_word[i].clear();
        }
        //getchar();
    }
    return 0;
}

