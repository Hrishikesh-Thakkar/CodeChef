#include<bits/stdc++.h>
using namespace std;

//20 points partial
int main(){
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int x; cin>>x;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		if(x>=a[0]) cout<<n<<endl;
		else{
			int num = a[0];
			int ans = 0;
			while(x<num){
				x*=2; ans++;
			}
			ans+=n;
			cout<<ans<<endl;
		}
	}
	return 0;
}