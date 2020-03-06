#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long ans = 0;
		int n;
		cin>>n;
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		for(int i=0;i<n;i++)
			ans+=min(a[i],b[i]);
		cout<<ans<<endl;
	}
	return 0;
}