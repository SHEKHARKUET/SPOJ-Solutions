#include <bits/stdc++.h>
 
using namespace std;
 
int n,dp[100002][3],arr[100002][3];
 
int rec(int i,int j)
{
    if(dp[i][j]!=-1)return dp[i][j];
    if(j==0)
    {
        if(i==n-1) dp[i][j] = arr[i][j]+rec(i,j+1);
        else dp[i][j] = arr[i][j]+min(min(rec(i+1,j),rec(i+1,j+1)),rec(i,j+1));
    }
    else if(j==1)
    {
        if(i==n-2) dp[i][j] = arr[i][j]+min(min(rec(i+1,j-1),rec(i+1,j)),rec(i,j+1));
        else if(i==n-1) return arr[i][j];
        else dp[i][j] = arr[i][j]+min(min(rec(i+1,j-1),rec(i+1,j)),min(rec(i+1,j+1),rec(i,j+1)));
    }
    else
    {
        if(i==n-2) dp[i][j] = arr[i][j]+rec(i+1,j-1);
        else dp[i][j] = arr[i][j]+min(rec(i+1,j),rec(i+1,j-1));
    }
    return dp[i][j];
}
 
int main()
{
    int i,j,x=1;
    while(scanf("%d",&n)==1)
    {
        if(n==0)break;
        for(i=0;i<n;i++)
            for(j=0;j<3;j++)scanf("%d",&arr[i][j]);
        memset(dp,-1,sizeof dp);
        printf("%d. %d\n",x,rec(0,1));
        x++;
    }
    return 0;
}