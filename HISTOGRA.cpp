#include <bits/stdc++.h>
 
using namespace std;
 
long long arr[100002];
int n;
 
struct info
{
    long long val;
    int idx;
}tree[300007];
 
void create(int b,int e,int node)
{
    if(b==e)
    {
        tree[node].val=arr[b];
        tree[node].idx=b;
        return;
    }
    int left,right,mid;
    left=node*2;
    right=left+1;
    mid=(b+e)/2;
    create(b,mid,left);
    create(mid+1,e,right);
    tree[node].val=min(tree[left].val,tree[right].val);
    if(tree[node].val==tree[left].val)tree[node].idx=tree[left].idx;
    else tree[node].idx=tree[right].idx;
}
 
info query(int b,int e,int node,int i,int j)
{
    if(b>=i&&e<=j)return tree[node];
    int left,right,mid;
    info t1,t2,temp;
    left=node*2;
    right=left+1;
    mid=(b+e)/2;
    if(j<=mid)return query(b,mid,left,i,j);
    else if(i>mid)return query(mid+1,e,right,i,j);
    else
    {
        t1=query(b,mid,left,i,j);
        t2=query(mid+1,e,right,i,j);
        temp.val = min(t1.val,t2.val);
        if(temp.val==t1.val)temp.idx=t1.idx;
        else temp.idx=t2.idx;
        return temp;
    }
}
 
long long retMax(int b,int e)
{
    if(b==e)return arr[b];
    if(b>e)return 0;
    long long mx;
    int mid;
    info temp;
    temp=query(0,n-1,1,b,e);
    mid=temp.idx;
    mx=max((e-b+1)*temp.val,max(retMax(b,mid-1),retMax(mid+1,e)));
    return mx;
}
 
int main()
{
    int i;
    while(scanf("%d",&n)==1)
    {
        if(n==0)break;
        for(i=0;i<n;i++)scanf("%lld",&arr[i]);
        create(0,n-1,1);
        printf("%lld\n",retMax(0,n-1));
    }
}