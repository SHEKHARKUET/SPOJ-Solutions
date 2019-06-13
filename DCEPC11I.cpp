#include <bits/stdc++.h>
 
using namespace std;
 
struct st
{
    long long sum,start,cnt;
}tree[400005];
 
void propagate(int node,int b,int e)
{
    long long start1,start2,cnt1,cnt2,l1,l2;
    l1=(b+e)/2-b+1;l2=e-(b+e)/2;cnt1=cnt2=tree[node].cnt;
    start1=tree[node].start;
    start2=tree[node].start+(tree[node].cnt*l1);
 
    tree[node*2].sum+=(start1-cnt1)*l1+(cnt1*l1*(l1+1))/2;
    tree[node*2].start+=start1;
    tree[node*2].cnt+=cnt1;
 
    tree[node*2+1].sum+=(start2-cnt2)*l2+(cnt2*l2*(l2+1))/2;
    tree[node*2+1].start+=start2;
    tree[node*2+1].cnt+=cnt2;
 
    tree[node].start=tree[node].cnt=0;
}
 
void upd(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)return;
    if(b>=i && e<=j)
    {
        long long l=e-b+1;long long s=b-i+1;
        tree[node].sum+=(s-1)*l+(l*(l+1))/2;
        tree[node].start+=s;
        tree[node].cnt++;
        return;
    }
    if(tree[node].cnt)propagate(node,b,e);
    int left,right,mid;
    mid=(b+e)/2;left=node*2;right=left+1;
    upd(left,b,mid,i,j);
    upd(right,mid+1,e,i,j);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
 
long long query(int node,int b,int e,int i,int j)
{
    if(i>e||j<b)return 0;
    if(b>=i && e<=j)return tree[node].sum;
    if(tree[node].cnt)propagate(node,b,e);
    long long q1,q2;
    int left,right,mid;
    mid=(b+e)/2;left=node*2;right=left+1;
    q1=query(left,b,mid,i,j);
    q2=query(right,mid+1,e,i,j);
    return q1+q2;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n,i,q,type,l,r;
    for(i=0;i<400000;i++){tree[i].cnt=tree[i].start=tree[i].sum=0;}
    cin>>n>>q;
    for(i=0;i<q;i++)
    {
        cin>>type>>l>>r;
        if(type)cout<<query(1,0,n-1,l-1,r-1)<<"\n";
        else upd(1,0,n-1,l-1,r-1);
    }
    return 0;
}