#include <bits/stdc++.h>
 
using namespace std;
 
int arr[100002];
 
struct info
{
    int maxVal;
    pair<int,int>leftMax,rightMax;
}tree[300007];
 
void create(int b,int e,int node)
{
    if(b==e)
    {
        tree[node].maxVal=1;
        tree[node].leftMax.first=tree[node].rightMax.first=arr[b];
        tree[node].leftMax.second=tree[node].rightMax.second=1;
        //cout<<"yjyjyj"<<endl;
        return;
    }
    int left,right,mid;
    mid=(b+e)/2;
    left=node*2;
    right=left+1;
    create(b,mid,left);
    create(mid+1,e,right);
    if(tree[right].rightMax.first==tree[left].rightMax.first)
    {
        tree[node].rightMax.first=tree[left].rightMax.first;
        tree[node].rightMax.second=tree[right].maxVal+tree[left].rightMax.second;
    }
    else tree[node].rightMax=tree[right].rightMax;
    if(tree[left].leftMax.first==tree[right].leftMax.first)
    {
        tree[node].leftMax.first=tree[right].leftMax.first;
        tree[node].leftMax.second=tree[left].maxVal+tree[right].leftMax.second;
    }
    else tree[node].leftMax=tree[left].leftMax;
    if(tree[left].rightMax.first==tree[right].leftMax.first)
        tree[node].maxVal=max(tree[left].rightMax.second+tree[right].leftMax.second,max(tree[left].maxVal,tree[right].maxVal));
    else tree[node].maxVal=max(tree[left].maxVal,tree[right].maxVal);
 
}
 
info query(int b,int e,int node,int i,int j)
{
    if(b>=i&&e<=j)return tree[node];
    int left,right,mid;
    info t1,t2,t;
    mid=(b+e)/2;
    left=node*2;
    right=left+1;
    if(j<=mid)t=query(b,mid,left,i,j);
    else if(i>mid)t=query(mid+1,e,right,i,j);
    else
    {
        t1=query(b,mid,left,i,j);
        t2=query(mid+1,e,right,i,j);
        if(t2.rightMax.first==t1.rightMax.first)
        {
            t.rightMax.first=t1.rightMax.first;
            t.rightMax.second=t2.maxVal+t1.rightMax.second;
        }
        else t.rightMax=t2.rightMax;
        if(t1.leftMax.first==t2.leftMax.first)
        {
            t.leftMax.first=t2.leftMax.first;
            t.leftMax.second=t1.maxVal+t2.leftMax.second;
        }
        else t.leftMax=t1.leftMax;
        if(t1.rightMax.first==t2.leftMax.first)
            t.maxVal=max(t1.rightMax.second+t2.leftMax.second,max(t1.maxVal,t2.maxVal));
        else t.maxVal=max(t1.maxVal,t2.maxVal);
    }
    return t;
}
 
int main()
{
    int n,q,i,x,y;
    while(scanf("%d",&n)==1)
    {
        if(n==0)break;
        scanf("%d",&q);
        for(i=0;i<n;i++)scanf("%d",&arr[i]);
        create(0,n-1,1);
        for(i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",query(0,n-1,1,x-1,y-1).maxVal);
        }
    }
    return 0;
}