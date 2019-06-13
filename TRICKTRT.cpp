#include <bits/stdc++.h>
#define SMALL -9999999999999
#define prec .00000001
 
using namespace std;
 
double minDist(int n,double arr[50002][2],double x)
{
    double mxm=SMALL,val;
    for(int i=0;i<n;i++)
    {
        val=sqrt((x-arr[i][0])*(x-arr[i][0])+arr[i][1]*arr[i][1]);
        if(val>mxm)mxm=val;
    }
    //cout<<mnm<<endl;
    return mxm;
}
 
pair<double,double> binsearch(int n,double arr[50002][2])
{
    double hi=-200002,lo=200002,mid,x;
    int i,j;
    for(i=0;i<n;i++)
    {
        if(arr[i][0]<lo)lo=arr[i][0];
        if(arr[i][0]>hi)hi=arr[i][0];
    }
    for(i=0;i<100;i++)
    {
        mid=(lo+hi)/2;
        x=minDist(n,arr,mid);
        //cout<<x<<endl;
        if(x>minDist(n,arr,mid+prec))lo=mid+prec;
        else if(x>minDist(n,arr,mid-prec))hi=mid-prec;
    }
    return make_pair(mid,x);
}
 
int main()
{
    int n,i;
    double arr[50002][2];
    pair<double,double>pd;
    while(scanf("%d",&n)==1)
    {
        if(n==0)break;
        for(i=0;i<n;i++)scanf("%lf%lf",&arr[i][0],&arr[i][1]);
        pd=binsearch(n,arr);
        printf("%f %f\n",pd.first,pd.second);
        //cout<<binsearch(n,arr)<<endl;
    }
    return 0;
}