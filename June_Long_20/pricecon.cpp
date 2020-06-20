#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>> t;
	while(t--){
		int n,k; cin>>n>>k;
		int a[n]; for(int i=0;i<n;i++) cin>>a[i];
		int original_sum = 0; int new_sum = 0;
		for(int i=0;i<n;i++){
			original_sum+=a[i];
			new_sum += min(a[i],k);
		}
		cout<<original_sum - new_sum<<endl;
	}
	return 0;
}