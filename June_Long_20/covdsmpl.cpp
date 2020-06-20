#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,p;
		cin>>n>>p;
		int a[n][n];
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) a[i][j] = 0;
		for(int i=0;i<n;i++) for(int j=0;j<n;j++){
			int x;
			cout<<1<<" "<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+1<<endl;
			cin>>x;
			if(x==1) a[i][j] = 1;
			if(x==-1) exit(0);
		}
		cout<<2<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		int x; cin>>x;
		if(x==1) continue;
		else if(x==-1) exit(0);
	}
	return 0;
}