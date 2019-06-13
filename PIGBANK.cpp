#include <bits/stdc++.h>
#define BIG 2147483640
 
using namespace std;
 
int n,p[501],w[501],dp[501][10001];
bool flag;
 
int rec(int i,int weight)
{
    if(dp[i][weight]!=-1)return dp[i][weight];
    if(weight==0)
    {
        flag=true;
        return 0;
    }
    if(i==n)return BIG;
    int p1=BIG,p2;
    if(weight-w[i]>=0)p1=rec(i,weight-w[i]);
    if(p1!=BIG)p1=p[i]+p1;
    p2=rec(i+1,weight);
    dp[i][weight]=min(p1,p2);
    //cout<<dp[i][weight]<<endl;
    return dp[i][weight];
}
 
int main()
{
    int i,test,e,f,res;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d%d",&e,&f,&n);
        for(i=0;i<n;i++)scanf("%d%d",&p[i],&w[i]);
        memset(dp,-1,sizeof(dp));
        flag=false;
        res=rec(0,f-e);
        if(!flag)printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",res);
    }
    return 0;
}