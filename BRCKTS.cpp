#include <bits/stdc++.h>
 
using namespace std;
 
string str;
 
struct tree
{
    int l,r;
}mytree[90008];
 
void create(int b,int e,int node)
{
    if(b==e)
    {
        if(str[b]=='(')
        {
            mytree[node].l=1;
            mytree[node].r=0;
        }
        else
        {
            mytree[node].l=0;
            mytree[node].r=1;
        }
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    create(b,mid,left);
    create(mid+1,e,right);
    if(mytree[left].l<mytree[right].r)
    {
        mytree[node].l=mytree[right].l;
        mytree[node].r=mytree[right].r-mytree[left].l+mytree[left].r;
    }
    else
    {
        mytree[node].l=mytree[left].l-mytree[right].r+mytree[right].l;
        mytree[node].r=mytree[left].r;
    }
}
 
void update(int b,int e,int node,int i)
{
    if(i<b||i>e)return;
    if(b==e)
    {
        if(mytree[node].l==0){mytree[node].l=1;mytree[node].r=0;}
        else {mytree[node].l=0;mytree[node].r=1;}
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    update(b,mid,left,i);
    update(mid+1,e,right,i);
    if(mytree[left].l<mytree[right].r)
    {
        mytree[node].l=mytree[right].l;
        mytree[node].r=mytree[right].r-mytree[left].l+mytree[left].r;
    }
    else
    {
        mytree[node].l=mytree[left].l-mytree[right].r+mytree[right].l;
        mytree[node].r=mytree[left].r;
    }
}
 
bool balanced()
{
    if(mytree[1].l==0&&mytree[1].r==0)return true;
    else return false;
}
 
int main()
{
    int i,j,n,m,x;
    char s[30002];
    for(i=1;i<=10;i++)
    {
        printf("Test %d:\n",i);
        scanf("%d",&n);
        scanf("%30001s",&s);
        str=s;
        create(0,n-1,1);
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            scanf("%d",&x);
            if(x!=0)update(0,n-1,1,x-1);
            else
            {
                if(balanced())printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}