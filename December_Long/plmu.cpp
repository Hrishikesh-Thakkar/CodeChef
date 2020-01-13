#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		long long int two = 0,zero = 0;
		for(int i=0;i<n;i++)
		{	
			int a;
			cin>>a;
			if(a == 2)
				two++;
			if(a==0)
				zero++;		}
		int b,c,d,e;
		b = two;
		c = two-1;
		d = zero;
		e = zero - 1;
		if(b%2==0)
			b/=2;
		else
			c/=2;
		if(d%2==0)
			d/=2;
		else e/=2;
		cout<<b*c+d*e<<endl;

	}
	return 0;
}