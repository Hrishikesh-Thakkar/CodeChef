#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		int large = 0;
		int small = INT_MAX;
		int streak = 1;
		for(int i=1;i<n;i++){
			if(a[i]-a[i-1]<=2) streak++;
			else{
				large = max(large,streak);
				small = min(small,streak);
				streak = 1;
			}
		}
		large = max(large,streak);
		small = min(small,streak);
		cout<<small<<" "<<large<<endl;
	}
	return 0;
}