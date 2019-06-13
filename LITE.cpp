#include <bits/stdc++.h>
 
using namespace std;
 
struct info
{
    int sum;
    int prop;
}tree[300007];
 
void create(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=tree[node].prop=0;
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    create(left,b,mid);
    create(right,mid+1,e);
    tree[node].sum=tree[node].prop=0;
}
 
void update(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)return;
    if(b>=i && e<=j)
    {
        tree[node].prop++;
        tree[node].sum=(e-b+1)-tree[node].sum;
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
    if(tree[node].prop%2==0)tree[node].sum=tree[left].sum+tree[right].sum;
    else tree[node].sum=(e-b+1)-(tree[left].sum+tree[right].sum);
}
 
int query(int node,int b,int e,int i,int j,int carry)
{
    if(i>e||j<b)return 0;
    if(b>=i && e<=j)
    {
        if(carry%2==0)return tree[node].sum;
        else return ((e-b+1)-tree[node].sum);
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    int p1=query(left,b,mid,i,j,carry+tree[node].prop);
    int p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}
 
int main()
{
    int n,m,i,x,y,j;
    while(scanf("%d%d",&n,&m)==2)
    {
        create(1,0,n-1);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&j,&x,&y);
            if(j==0)update(1,0,n-1,x-1,y-1);
            else printf("%d\n",query(1,0,n-1,x-1,y-1,0));
            //for(j=1;j<=7;j++)cout<<tree[j].prop<<" "<<tree[j].sum<<endl;
        }
    }
    return 0;
}