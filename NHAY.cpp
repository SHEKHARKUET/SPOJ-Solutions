#include <bits/stdc++.h>
 
using namespace std;
 
long long MOD=1e9+9;
vector<long long>hv,power;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    long long n,i,val,ans,p,temp;
    char c;bool flag;
    while(cin>>n)
    {
        p = 1;ans=0;flag=false;
        for(i=0;i<n;i++)
        {
            cin>>c;
            temp=p*(c-'a'+1);
            if(temp>=MOD)temp=temp-(temp/MOD)*MOD;
            ans=(ans+temp);
            if(ans>=MOD)ans=ans-(ans/MOD)*MOD;
            p=(p*31);
            if(p>=MOD)p=p-(p/MOD)*MOD;
        }
        cin.get(c);power.push_back(1);hv.push_back(0);i=0;
        while(cin.get(c))
        {
            if(c<'a'||c>'z')break;
            long long temp = power[i]*(c-'a'+1);
            if(temp>=MOD)temp=temp-(temp/MOD)*MOD;
            temp=hv[i]+temp;
            if(temp>=MOD)temp=temp-(temp/MOD)*MOD;
            hv.push_back(temp);
            temp=power[i]*31;
            if(temp>=MOD)temp=temp-(temp/MOD)*MOD;
            power.push_back(temp);i++;
            if(i>=n)
            {
                val=(hv[i]-hv[i-n]+MOD);
                if(val>=MOD)val=val-(val/MOD)*MOD;
                if(val==(ans*power[i-n])%MOD)
                {
                    flag=true;
                    cout<<i-n<<"\n";
                }
            }
        }
        if(!flag)cout<<"\n\n";
        hv.clear();power.clear();
    }
    return 0;
}