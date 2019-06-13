#include <bits/stdc++.h>
 
using namespace std;
 
string str1,str2;
int dp[2001][2001];
 
int rec(int i,int j)
{
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==str1.length())return str2.length()-j;
    if(j==str2.length())return str1.length()-i;
    int a,b,c;
    if(str1[i]==str2[j])dp[i][j]=rec(i+1,j+1);
    else
    {
        a=1+rec(i+1,j+1);
        b=1+rec(i,j+1);
        c=1+rec(i+1,j);
        dp[i][j]=min(a,min(b,c));
    }
    return dp[i][j];
}
 
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        cin>>str1>>str2;
        memset(dp,-1,sizeof(dp));
        printf("%d\n",rec(0,0));
    }
    return 0;
}