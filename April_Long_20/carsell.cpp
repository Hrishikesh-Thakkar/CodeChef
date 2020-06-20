#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int mod = 1e9 + 7;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		int cnt = 0;
		int ans = 0;
		for(int i=n-1;i>=0;i--){
			ans = (ans + max(a[i]-cnt,0))%mod;
			cnt++;
		}
		cout<<ans<<endl;
	}
	return 0;
}