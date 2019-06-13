#include <bits/stdc++.h>
 
using namespace std;
 
bool ok(string str1,string str2,int k)
{
    int i=0,j=0,ii;
    while(true)
    {
        if(j==str2.length())return true;
        for(ii=0;ii<k;ii++)
        {
            if(i==str1.length())return false;
            while(str1[i]!=str2[j])
            {
                i++;
                if(i==str1.length())return false;
            }
            i++;
        }
        if(ii==k)j++;
    }
}
 
int binsearch(string str1,string str2)
{
    int lo=1,hi=str1.length()/str2.length(),res=0,mid;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(ok(str1,str2,mid)){lo=mid+1;res=mid;}
        else hi=mid-1;
    }
    return res;
}
 
int main()
{
    int test;
    string str1,str2;
    scanf("%d",&test);
    while(test--)
    {
        cin>>str2>>str1;
        printf("%d\n",binsearch(str1,str2));
    }
    return 0;
}