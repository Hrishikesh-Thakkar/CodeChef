#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long int tax = 0;
		if(n>250000){
			tax+=(min(n,500000)-250000)*0.05;
		}
		if(n>500000){
			tax+=(min(n,750000)-500000)*0.1;
		}
		if(n>750000){
			tax+=(min(n,1000000)-750000)*0.15;
		}
		if(n>1000000){
			tax+=(min(n,1250000)-1000000)*0.2;
		}
		if(n>1250000){
			tax+=(min(n,1500000)-1250000)*0.25;
		}
		if(n>1500000){
			tax+=(n-1500000)*0.3;
		}
		cout<<n-tax<<endl;
	}
	return 0;
}