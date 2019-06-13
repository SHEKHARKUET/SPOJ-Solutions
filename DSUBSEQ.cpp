///How many distinct subsequences are there in a string?
 
#include <bits/stdc++.h>
#define MOD 1000000007
 
using namespace std;
 
long long arr[26];
 
long long numofSubseq(string str)
{
    int i,l=str.length();
    long long sum=1,temp,sub;
    for(i=l-1;i>=0;i--)
    {
        temp=arr[str[i]-'A'];
        arr[str[i]-'A']=sum;
        ///sum=(sum%MOD+abs(sum-temp)%MOD)%MOD;
        sub=sum-temp;
        if(sub<0)sub=MOD+sub;
        sum=(sum%MOD+sub%MOD)%MOD;
    }
    return sum;
}
 
int main()
{
    int test;
    string str;
    scanf("%d",&test);
    while(test--)
    {
        cin>>str;
        memset(arr,0,sizeof(arr));
        printf("%lld\n",numofSubseq(str)%MOD);
    }
    return 0;
}