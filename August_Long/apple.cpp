#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	long long int k,n;
	while(t--){
	cin>>n>>k;
	n/=k;
	if(n%k==0)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	}
	return 0;
}