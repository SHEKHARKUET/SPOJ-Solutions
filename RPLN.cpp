#include <bits/stdc++.h>
 
using namespace std;
 
int arr[100002];
int tree[300007];
 
void create(int b,int e,int node)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)>>1;
    create(b,mid,left);
    create(mid+1,e,right);
    tree[node]=min(tree[left],tree[right]);
}
 
int query(int b,int e,int node,int i,int j)
{
    if(j<b||i>e)return INFINITY;
    if(b>=i&&e<=j)return tree[node];
    int q1,q2,left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)>>1;
    q1=query(b,mid,left,i,j);
    q2=query(mid+1,e,right,i,j);
    return min(q1,q2);
}
 
int main()
{
    int t,i,n,q,x,y,j=1;
    scanf("%d",&t);
    while(t--)
    {
        printf("Scenario #%d:\n",j);
        scanf("%d",&n);
        scanf("%d",&q);
        for(i=0;i<n;i++)scanf("%d",&arr[i]);
        create(0,n-1,1);
        for(i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",query(0,n-1,1,x-1,y-1));
        }
        j++;
    }
    return 0;
}