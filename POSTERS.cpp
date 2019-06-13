#include <bits/stdc++.h>
 
using namespace std;
 
int a[100000];
set<int>st;
struct tree
{
    bool oc;
    int val;
}mytree[300000];
 
void create(int b,int e,int node)
{
    if(b==e)
    {
        mytree[node].oc=false;
        mytree[node].val=0;
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    create(b,mid,left);
    create(mid+1,e,right);
    mytree[node].oc=false;
    mytree[node].val=0;
}
 
void update(int b,int e,int node,int i,int j,int col)
{
    if(j<b||i>e)return;
    if(b>=i&&e<=j)
    {
        mytree[node].oc=true;
        mytree[node].val=col;
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    if(mytree[node].oc)mytree[left].oc=mytree[right].oc=true;
    if(mytree[node].oc)mytree[left].val=mytree[right].val=mytree[node].val;
    update(b,mid,left,i,j,col);
    update(mid+1,e,right,i,j,col);
    mytree[node].oc=false;
}
 
void query(int b,int e,int node)
{
    if(mytree[node].oc)
    {
        st.insert(mytree[node].val);
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    query(b,mid,left);
    query(mid+1,e,right);
}
 
int main()
{
    int t,n,i,j,k,mn,mx;
    vector<int>v[2];
    set<int>s;
    set<int>::iterator it;
    map<int,int>mp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(k=0;k<n;k++)
        {
            scanf("%d%d",&i,&j);
            v[0].push_back(i);
            v[1].push_back(j);
            s.insert(i);
            s.insert(j);
        }
        k=mn=1;
        for(it=s.begin();it!=s.end();it++)
        {
            mp.insert(std::pair<int,int>(*it,k));
            k++;
        }
        mx=k-1;
        create(mn,mx,1);
        for(k=0;k<n;k++)update(mn,mx,1,mp[v[0][k]],mp[v[1][k]],k+1);
        //cout<<mytree[2].val<<" "<<mytree[3].val<<endl;
        query(mn,mx,1);
        printf("%d\n",st.size());
        st.clear();
        v[0].clear();
        v[1].clear();
        s.clear();
        mp.clear();
    }
    return 0;
}