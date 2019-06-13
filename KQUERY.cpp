#include <bits/stdc++.h>
 
using namespace std;
 
int arr[30002],b[200000][3];
int tree[90009];
 
int readInt () {
bool minus = false;
int result = 0;
char ch;
ch = getchar();
while (true) {
if (ch == '-') break;
if (ch >= '0' && ch <= '9') break;
ch = getchar();
}
if (ch == '-') minus = true; else result = ch-'0';
while (true) {
ch = getchar();
if (ch < '0' || ch > '9') break;
result = result*10 + (ch - '0');
}
if (minus)
return -result;
else
return result;
}
 
void create(int b,int e,int node)
{
    if(b==e)
    {
        tree[node]=1;
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    create(b,mid,left);
    create(mid+1,e,right);
    tree[node]=tree[left]+tree[right];
}
 
void update(int b,int e,int node,int i)
{
    if(i<b||i>e)return;
    if(b==e)
    {
        tree[node]=0;
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    update(b,mid,left,i);
    update(mid+1,e,right,i);
    tree[node]=tree[left]+tree[right];
}
 
int query(int b,int e,int node,int i,int j)
{
    if(j<b||i>e)return 0;
    if(b>=i&&e<=j)return tree[node];
    int left,right,mid,q1,q2;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    q1=query(b,mid,left,i,j);
    q2=query(mid+1,e,right,i,j);
    return q1+q2;
}
 
int main()
{
    int n,i,q,a[30002],res[200002],x,y,z;
    bool flag;
    multimap<int,int>mp1;
    multimap<int,int*>mp2;
    multimap<int,int>::iterator it;
    multimap<int,int*>::iterator itr;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            //scanf("%d",&a[i]);
            a[i]=readInt();
            mp1.insert(std::pair<int,int>(a[i],i));
        }
        //scanf("%d",&q);
        q=readInt();
        for(i=0;i<q;i++)
        {
            //scanf("%d%d%d",&x,&y,&z);
            x=readInt();
            y=readInt();
            z=readInt();
            b[i][0]=i;
            b[i][1]=x-1;
            b[i][2]=y-1;
            mp2.insert(std::pair<int,int*>(z,b[i]));
        }
        memset(arr,1,sizeof arr);
        create(0,n-1,1);
        itr=mp2.begin();
        flag=false;
        for(it=mp1.begin();it!=mp1.end();it++)
        {
            if(itr==mp2.end())break;
            if(flag==true)
            {
                it--;
                flag=false;
            }
            if(it->first<=itr->first)update(0,n-1,1,it->second);
            else
            {
                res[(itr->second)[0]]=query(0,n-1,1,(itr->second)[1],(itr->second)[2]);
                if(it==mp1.begin())flag=true;
                else it--;
                itr++;
            }
        }
        while(itr!=mp2.end())
        {
            res[(itr->second)[0]]=query(0,n-1,1,(itr->second)[1],(itr->second)[2]);
            itr++;
        }
        for(i=0;i<q;i++)printf("%d\n",res[i]);
        mp1.clear();
        mp2.clear();
    }
    return 0;
}