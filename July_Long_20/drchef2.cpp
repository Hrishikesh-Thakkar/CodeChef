#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--){
		int n,x; cin>>n>>x;
		int a[n]; for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		//x is greater than all the numbers in the array
		if(a[n-1]<=x) cout<<n<<endl;
		//all nums are the same or single number
		else if(a[0]==a[n-1]){
			int num = a[0];
			int ans = 0;
			while(x<num){
				x*=2; ans++;
			}
			ans+=n;
			cout<<ans<<endl;
		}
		else{
			//all other cases need to be handled here
			int count = 0;
			int skips = 0;
			int pos = 0;
			while(pos<n){
				if(x>=a[pos]){
					while(2*a[pos]<x){
						pos++;
						skips++;
					}
					if(x>=a[pos]){
						x = 2*a[pos];
						pos++;
					}
					else x*=2;
				}
				else{
					x*=2;
				}
				count++;
			}
		 cout<<count+skips<<endl;
		}
	}	
	return 0;
}