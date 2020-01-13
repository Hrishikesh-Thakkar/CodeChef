#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		unsigned long long int a,s,b,c,d,e;
		cin>>a;
		s = 2*(pow(10,n));
		s += a;
		cout<<s<<endl;
		fflush(stdout);
		cin>>b;
		c = pow(10,n);
		c-=b;
		cout<<c<<endl;
		fflush(stdout);
		cin>>d;
		e = pow(10,n);
		e -= d;
		cout<<e<<endl;
		fflush(stdout);
		int ans;
		cin>>ans;
		if(ans==-1)
			break;
	}
	return 0;
}