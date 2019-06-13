#include <bits/stdc++.h>
 
using namespace std;
 
bool ok(int sum[],int k,int val,int n)
{
    int i=0,x=0;
    while(true)
    {
        if(k==0)return false;
        while(sum[i]-x<=val)
        {
            i++;
            if(i==n)return true;
        }
        x=sum[i-1];
        k--;
    }
}
 
int binsearch(int arr[],int sum[],int k,int n)
{
    sort(arr,arr+n);
    int lo=arr[0],hi=0,i,mid,res;
    for(i=k-1;i<n;i++)hi+=arr[i];
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        if(ok(sum,k,mid,n)){hi=mid-1;res=mid;}
        else lo=mid+1;
    }
    return res;
}
 
void solution(int arr[],int k,int n,int sum)
{
    int i,x=0;
    bool place[502];
    memset(place,false,sizeof(place));
    for(i=n-1;i>0;i--)
    {
        if(x+arr[i]>sum)
        {
            place[i]=true;
            x=0;
            k--;
        }
        x+=arr[i];
    }
    for(i=0;(i<n)&&(k>0);i++)if(!place[i]){place[i]=true;k--;}
    for(i=0;i<n;i++)
    {
        if(i==0)printf("%d",arr[i]);
        else printf(" %d",arr[i]);
        if(place[i])printf(" /");
    }
    printf("\n");
}
 
int main()
{
    int test,i,n,k,arr[502],temp[502],sum[502];
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(i==0)sum[0]=arr[0];
            else sum[i]=sum[i-1]+arr[i];
            temp[i]=arr[i];
        }
        solution(temp,k-1,n,binsearch(arr,sum,k,n));
    }
    return 0;
}