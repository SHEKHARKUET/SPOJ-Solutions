#include <bits/stdc++.h>
 
using namespace std;
 
int tree[600007];
 
void update(int node,int b,int e,int i)
{
    if(b==i && e==i)
    {
        tree[node]++;
        return;
    }
    if(i<b || i>e)return;
    int left,right,mid;
    left=node*2;
    right=left+1;
    mid=(b+e)/2;
    update(left,b,mid,i);
    update(right,mid+1,e,i);
    tree[node]=tree[left]+tree[right];
}
 
int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)return 0;
    if(b>=i && e<=j)return tree[node];
    int left,right,mid;
    left=node*2;
    right=left+1;
    mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}
 
int main()
{
    int test,n,i,arr[200003];
    long long cnt;
    vector< pair< int,int> > v;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            v.push_back(make_pair(arr[i],i));
        }
        sort(v.rbegin(),v.rend());
        cnt=0;
        memset(tree,0,sizeof(tree));
        for(i=0;i<n;i++)
        {
            cnt+=(long long)query(1,0,n-1,0,v[i].second);
            update(1,0,n-1,v[i].second);
        }
        printf("%lld\n",cnt);
        v.clear();
    }
    return 0;
}