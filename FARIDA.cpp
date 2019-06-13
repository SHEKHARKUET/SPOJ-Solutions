#include <bits/stdc++.h>
 
using namespace std;
 
long long dp[10002];
int arr[10002];
 
long long rec(int i)
{
    if(i<0)return 0;
    if(dp[i]!=-1)return dp[i];
    dp[i]=max(arr[i]+rec(i-2),rec(i-1));
    return dp[i];
}
 
int main()
{
    int test,n,i,caseno=0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",&arr[i]);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",++caseno,rec(n-1));
    }
    return 0;
}