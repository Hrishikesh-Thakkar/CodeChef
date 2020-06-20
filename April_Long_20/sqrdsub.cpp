#include<bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
			int n;
			cin>>n;
			int a[n];
			int ans = 0;
			int prod;
			for(int i=0;i<n;i++) cin>>a[i];
			for(int i=0;i<n;i++){

				if(abs(a[i]%4)!=2) ans++;
				prod = a[i];
				for(int j=i+1;j<n;j++){
					prod*=a[j];
					if(abs(prod)%4!=2) ans++; 
				}
			}
			cout<<ans<<endl;
	}
	return 0;
}