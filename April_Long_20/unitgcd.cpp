#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<max(1,n/2)<<"\n";
		if(n==1){
			cout<<1<<" "<<1<<"\n";
		}
		else if(n%2==0){
			for(int i=1;i<=n;i++){
				if(i%2==1) cout<<2<<" ";
				cout<<i<<" ";cout<<++i;
				if(i%2==0) cout<<"\n";
			}
		}
		else{
			for(int i=1;i<=n-3;i++){
				if(i%2==1) cout<<2<<" ";
				cout<<i<<" ";cout<<++i;
				if(i%2==0) cout<<"\n";
			}
			cout<<3<<" "<<n-2<<" "<<n-1<<" "<<n<<"\n";

		}
	}
	return 0;
}