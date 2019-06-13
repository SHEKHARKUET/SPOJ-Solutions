#include <bits/stdc++.h>
 
using namespace std;
 
int arr[21];
 
int maxxor(int j,int n,int k,int res)
{
    if(k==0)return res;
    int mxm=0;
    for(int i=j;i<n;i++)
    {
        if(res==-1)
        {
            if(i>n-k)break;
            mxm=max(mxm,maxxor(i+1,n,k-1,arr[i]));
        }
        else mxm=max(mxm,maxxor(i+1,n,k-1,arr[i]^res));
    }
    return mxm;
}
 
int main()
{
    int test,n,k,i;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)scanf("%d",&arr[i]);
        printf("%d\n",maxxor(0,n,k,-1));
    }
    return 0;
}