#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n; cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		map<int,int> m;
		int not_possible = 0;
		m[5] = 0,m[10] = 0,m[15] = 0;
		for(int i=0;i<n;i++){
			if(a[i]==5){
				m[5]++;
			}
			else if(a[i]==10){
				if(m[5]>0){
					m[5]--; m[10]++;
				}
				else {
					not_possible = 1;break;
				}
			}
			else{
				if(m[10]>0){
					//logic here
					m[10]--; m[15]++;
				}
				else if(m[5]>1){
					m[5]-=2; m[15]++;
				}
				else {not_possible = 1; break;}
			}
		} 		
		if(not_possible) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}