#include <bits/stdc++.h>
 
using namespace std;
 
int arr[50002];
 
struct info
{
    int sum,leftMax,rightMax,maxSeg;
}tree[150007];
 
void create(int b,int e,int node)
{
    if(b==e)
    {
        tree[node].sum=tree[node].leftMax=tree[node].rightMax=tree[node].maxSeg=arr[b];
        return;
    }
    int left,right,mid;
    mid=(b+e)/2;
    left=node*2;
    right=left+1;
    create(b,mid,left);
    create(mid+1,e,right);
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].leftMax=max(tree[left].leftMax,tree[left].sum+tree[right].leftMax);
    tree[node].rightMax=max(tree[right].rightMax,tree[right].sum+tree[left].rightMax);
    tree[node].maxSeg=max(tree[left].rightMax+tree[right].leftMax,max(tree[left].maxSeg,tree[right].maxSeg));
}
 
void update(int b,int e,int node,int i,int v)
{
    if(i<b||i>e)return;
    if(b==e && b==i)
    {
        tree[node].sum=tree[node].leftMax=tree[node].rightMax=tree[node].maxSeg= v;
        return;
    }
    int left,right,mid;
    mid=(b+e)/2;
    left=node*2;
    right=left+1;
    update(b,mid,left,i,v);
    update(mid+1,e,right,i,v);
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].leftMax=max(tree[left].leftMax,tree[left].sum+tree[right].leftMax);
    tree[node].rightMax=max(tree[right].rightMax,tree[right].sum+tree[left].rightMax);
    tree[node].maxSeg=max(tree[left].rightMax+tree[right].leftMax,max(tree[left].maxSeg,tree[right].maxSeg));
}
 
info query(int b,int e,int node,int i,int j)
{
    if(b>=i&&e<=j)return tree[node];
    int left,right,mid;
    mid=(b+e)/2;
    left=node*2;
    right=left+1;
    info t1,t2,t;
    if(j<=mid)t=query(b,mid,left,i,j);
    else if(i>mid)t=query(mid+1,e,right,i,j);
    else
    {
        t1=query(b,mid,left,i,j);
        t2=query(mid+1,e,right,i,j);
        t.sum=t1.sum+t2.sum;
        t.leftMax=max(t1.leftMax,t1.sum+t2.leftMax);
        t.rightMax=max(t2.rightMax,t2.sum+t1.rightMax);
        t.maxSeg=max(t1.rightMax+t2.leftMax,max(t1.maxSeg,t2.maxSeg));
    }
    return t;
}
 
int main()
{
    int n,q,i,j,x,y;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)scanf("%d",&arr[i]);
        create(0,n-1,1);
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%d%d%d",&j,&x,&y);
            if(j==0)update(0,n-1,1,x-1,y);
            else printf("%d\n",query(0,n-1,1,x-1,y-1).maxSeg);
        }
    }
    return 0;
}