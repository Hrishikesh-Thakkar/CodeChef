#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n; cin>>n;
		int x_or,y_or;
		cin>>x_or>>y_or;
		for(int i=1;i<4*n-1;i++){
			int x,y; cin>>x>>y;
			x_or^=x; y_or^=y;
		}
		cout<<x_or<<" "<<y_or<<endl;
	}
	return 0;
}