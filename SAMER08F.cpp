#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	// your code here
	int i, n;
	unsigned long long prev,sum;
	while(cin>>n && n)
	{
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		prev=1;
		for(i=2;i<=n;i++)
		{
			sum=prev+(i*(i-1))+i;
			prev=sum;
		}
		cout<<sum<<endl;
	}
	return 0;
} 