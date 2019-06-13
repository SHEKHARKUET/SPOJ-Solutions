#include <bits/stdc++.h>
 
using namespace std;
 
int arr[100002];
struct tree
{
    int a[3],updated;
    void change(){
        int x;
        x=this->a[2];
        this->a[2]=this->a[1];
        this->a[1]=this->a[0];
        this->a[0]=x;
    }
}mytree[300008];
 
void create(int b,int e,int node)
{
    if(b==e)
    {
        mytree[node].updated=0;
        mytree[node].a[0]=1;
        mytree[node].a[1]=mytree[node].a[2]=0;
        return;
    }
    int mid,left,right;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    create(b,mid,left);
    create(mid+1,e,right);
    for(int i=0;i<3;i++)mytree[node].a[i]=mytree[left].a[i]+mytree[right].a[i];
}
 
void update(int b,int e,int node,int i,int j)
{
    int x,y;
    if(j<b||i>e)return;
    if(b>=i&&e<=j)
    {
        mytree[node].updated++;
        mytree[node].change();
        return;
    }
    int mid,left,right;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    update(b,mid,left,i,j);
    update(mid+1,e,right,i,j);
    for(x=0;x<3;x++)
    {
        y=(x+mytree[node].updated)%3;
        mytree[node].a[y]=mytree[left].a[x]+mytree[right].a[x];
    }
}
 
tree query(int b,int e,int node,int i,int j,int carry)
{
    int x,y;
    if(j<b||i>e)
    {
        tree tr;
        tr.updated=tr.a[0]=tr.a[1]=tr.a[2]=0;
        return tr;
    }
    if(b>=i&&e<=j)
    {
        tree tt;
        tt=mytree[node];
        if(carry%3==1)tt.change();
        else if(carry%3==2)
        {
            tt.change();
            tt.change();
        }
        return tt;
    }
    int mid,left,right;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    tree t,t1,t2;
    t1=query(b,mid,left,i,j,carry+mytree[node].updated);
    t2=query(mid+1,e,right,i,j,carry+mytree[node].updated);
    for(x=0;x<3;x++)t.a[x]=t1.a[x]+t2.a[x];
    return t;
}
 
int main()
{
    int i,n,q,c,x,y;
    ofstream out;
    //out.open("tuna.txt");
    while(scanf("%d%d",&n,&q)==2)
    {
        for(i=1;i<=n;i++)arr[i]=0;
        create(1,n,1);
        for(i=0;i<q;i++)
        {
            scanf("%d%d%d",&c,&x,&y);
            if(c==0)update(1,n,1,x+1,y+1);
            else printf("%d\n",query(1,n,1,x+1,y+1,0).a[0]);
            //out<<query(1,n,1,x+1,y+1,0).a[0]<<endl;
        }
    }
    return 0;
}