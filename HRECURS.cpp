#include <bits/stdc++.h>
 
using namespace std;
 
int sum(int n,int arr[])
{
    if(n==0)return 0;
    return arr[n-1]+sum(n-1,arr);
}
 
int main()
{
    int test,n,arr[100],i,caseno=0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",&arr[i]);
        printf("Case %d: %d\n",++caseno,sum(n,arr));
    }
    return 0;
}