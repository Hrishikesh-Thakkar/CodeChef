#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];

		int maxi = 0;
		for(int i=0;i<n;i++){
			int num = a[i]*20 - b[i]*10;
			maxi=max(maxi,num);
		}
		cout<<maxi<<endl;
	}
	return 0;
}