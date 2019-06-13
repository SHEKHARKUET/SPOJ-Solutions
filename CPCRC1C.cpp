#include <bits/stdc++.h>
 
using namespace std;
 
vector<int>digitA,digitB;
long long dp[11][100][2];
 
vector<int> digitArray(int num)
{
    vector<int>v;
    while(num!=0)
    {
        v.push_back(num%10);
        num=num/10;
    }
    return v;
}
 
long long rec(int idx,int sum,int tight,vector<int>&v)
{
    if(idx==-1)return sum;
    if(dp[idx][sum][tight]!=-1 && tight!=1)return dp[idx][sum][tight];
    int newTight,k,i;
    k = tight ? v[idx]:9;
    long long ans=0,ret;
    for(i=0;i<=k;i++)
    {
        newTight = (tight && i==k) ? 1:0;
        ans+=rec(idx-1,sum+i,newTight,v);
    }
    if(!tight)dp[idx][sum][tight]=ans;
    //dp[idx][sum][tight]=ans;
    return ans;
}
 
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==-1&&m==-1)break;
        digitA=digitArray(n-1);
        digitB=digitArray(m);
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",rec(digitB.size()-1,0,1,digitB)-rec(digitA.size()-1,0,1,digitA));
        digitA.clear();
        digitB.clear();
    }
    return 0;
}