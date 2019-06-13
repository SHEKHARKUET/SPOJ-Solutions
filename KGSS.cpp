#include <bits/stdc++.h>
 
using namespace std;
 
int arr[200002];
 
struct tree
{
    int mx,nx;
}mytree[600007];
 
void create(int b,int e,int node)
{
    if(b==e)
    {
        mytree[node].mx=arr[b];
        mytree[node].nx=0;
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    create(b,mid,left);
    create(mid+1,e,right);
    mytree[node].mx=max(mytree[left].mx,mytree[right].mx);
    mytree[node].nx=max(min(mytree[left].mx,mytree[right].mx),max(mytree[left].nx,mytree[right].nx));
}
 
tree query(int b,int e,int node,int i,int j)
{
    if(j<b||i>e)
    {
        tree tr;
        tr.mx=tr.nx=0;
        return tr;
    }
    if(b>=i&&e<=j)return mytree[node];
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    tree t1,t2,t;
    t1=query(b,mid,left,i,j);
    t2=query(mid+1,e,right,i,j);
    t.mx=max(t1.mx,t2.mx);
    t.nx=max(min(t1.mx,t2.mx),max(t1.nx,t2.nx));
    return t;
}
 
void update(int b,int e,int node,int idx,int val)
{
    if(idx<b||idx>e)return;
    if(b==e)
    {
        mytree[node].mx=val;
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    update(b,mid,left,idx,val);
    update(mid+1,e,right,idx,val);
    mytree[node].mx=max(mytree[left].mx,mytree[right].mx);
    mytree[node].nx=max(min(mytree[left].mx,mytree[right].mx),max(mytree[left].nx,mytree[right].nx));
}
 
int main()
{
    int n,i,q,x,y;
    char c;
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++)scanf("%d",&arr[i]);
        create(1,n,1);
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            cin>>c;
            scanf("%d%d",&x,&y);
            if(c=='Q')
                printf("%d\n",query(1,n,1,x,y).mx+query(1,n,1,x,y).nx);
            else
                update(1,n,1,x,y);
        }
    }
    return 0;
}