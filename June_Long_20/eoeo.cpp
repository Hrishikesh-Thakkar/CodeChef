#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--){
		long long int ts; cin>>ts;
		long long int a = ts;
		// from 2 to ts
		// find all numbers having more factors of two than ts and lesser than ts
		int initial_zeros = 0;
		while(a%2==0) {a/=2; initial_zeros++;}
		for(int i=0;i<initial_zeros;i++)
			ts/=2;
		cout<<ts/2<<endl;

	}
	return 0;
}