#include <bits/stdc++.h>
 
using namespace std;
 
long long arr[50003];
 
struct info
{
    long long sum,maxLeft,maxRight,maxSeg;
}tree[150007];
 
void create(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=tree[node].maxLeft=tree[node].maxRight=tree[node].maxSeg=arr[b];
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    create(left,b,mid);
    create(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].maxLeft=max(tree[left].maxLeft,tree[left].sum+tree[right].maxLeft);
    tree[node].maxRight=max(tree[right].maxRight,tree[right].sum+tree[left].maxRight);
    tree[node].maxSeg=max(tree[left].maxRight+tree[right].maxLeft,max(tree[left].maxSeg,tree[right].maxSeg));
}
 
info query(int node,int b,int e,int i,int j)
{
    if(b>=i && e<=j)return tree[node];
    int left,right,mid;
    info t,t1,t2;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    if(j<=mid)t=query(left,b,mid,i,j);
    else if(i>mid)t=query(right,mid+1,e,i,j);
    else
    {
        t1=query(left,b,mid,i,j);
        t2=query(right,mid+1,e,i,j);
        t.sum=t1.sum+t2.sum;
        t.maxLeft=max(t1.maxLeft,t1.sum+t2.maxLeft);
        t.maxRight=max(t2.maxRight,t2.sum+t1.maxRight);
        t.maxSeg=max(t1.maxRight+t2.maxLeft,max(t1.maxSeg,t2.maxSeg));
    }
    return t;
}
 
int main()
{
    int n,i,x,y,m;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)scanf("%lld",&arr[i]);
        create(1,0,n-1);
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(1,0,n-1,x-1,y-1).maxSeg);
        }
    }
    return 0;
}