#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--){
		int n; cin>>n; 
		int a[n][n];
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) a[i][j] = 0;
		int num = 1;
		for(int i=0;i<n;i++){
			if(i%2==0){
				for(int j=0;j<n;j++) a[i][j] = num++;
			}
			else{
				for(int j=n-1;j>=0;j--) a[i][j] = num++;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				 cout<<a[i][j]<<" ";
				}
				cout<<endl;
			}
	}
	return 0;
}