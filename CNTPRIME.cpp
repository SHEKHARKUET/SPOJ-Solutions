#include <bits/stdc++.h>
 
using namespace std;
 
struct st
{
    int sum,lazy;
}tree[40007];
 
int arr[10005];
 
bool prime[1000005];
 
void sieve()
{
    int i,j;
    memset(prime,true,sizeof(prime));
    for(i=2;i<=1000;i++)
    {
        if(!prime[i])continue;
        for(j=2*i;j<1000000;j+=i)prime[j]=false;
    }
}
 
void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=arr[b];
        tree[node].lazy=-1;
        return;
    }
    int mid,left,right;
    mid=(b+e)/2;left=node*2;right=left+1;
    build(left,b,mid);build(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].lazy=-1;
}
 
void propagate(int node,int b,int e,int v)
{
    int mid=(b+e)/2;
    tree[node].lazy=-1;
    tree[node*2].lazy=v;
    tree[node*2+1].lazy=v;
    tree[node*2].sum=(mid-b+1)*v;
    tree[node*2+1].sum=(e-mid)*v;
}
 
void upd(int node,int b,int e,int l,int r,int v)
{
    if(e<l || b>r)return;
    if(b>=l && e<=r)
    {
        tree[node].lazy=v;
        tree[node].sum=(e-b+1)*v;
        return;
    }
    int left,right,mid;
    mid=(b+e)/2;left=node*2;right=left+1;
    if(tree[node].lazy!=-1)propagate(node,b,e,tree[node].lazy);
    upd(left,b,mid,l,r,v);upd(right,mid+1,e,l,r,v);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
 
int query(int node,int b,int e,int l,int r)
{
    if(e<l || b>r)return 0;
    if(b>=l && e<=r)return tree[node].sum;
    int mid,left,right,q1,q2;
    mid=(b+e)/2;left=node*2;right=left+1;
    if(tree[node].lazy!=-1)propagate(node,b,e,tree[node].lazy);
    q1=query(left,b,mid,l,r);q2=query(right,mid+1,e,l,r);
    return q1+q2;
}
 
int main()
{
    sieve();
    int test,caseno=0,n,q,i,type,l,r,v;
    scanf("%d",&test);
    while(test--)
    {
        printf("Case %d:\n",++caseno);
        scanf("%d%d",&n,&q);
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            arr[i]=prime[arr[i]];
        }
        build(1,0,n-1);
        for(i=0;i<q;i++)
        {
            scanf("%d",&type);
            if(type==1)
            {
                scanf("%d%d",&l,&r);
                printf("%d\n",query(1,0,n-1,l-1,r-1));
            }
            else
            {
                scanf("%d%d%d",&l,&r,&v);
                upd(1,0,n-1,l-1,r-1,prime[v]);
            }
        }
    }
    return 0;
}