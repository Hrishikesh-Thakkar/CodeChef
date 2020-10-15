#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		int maxi = -1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(maxi<a[i])
				maxi=a[i];
		}
		vector<int> pos;
		int ans = 0;
		for(int i = 1;i<=n;i++)
			if(a[i]==maxi)
				pos.push_back(i);
		pos.push_back(pos[0]+n);
		int sz = n/2;
		for(int i=1;i<pos.size();i++) ans += max(0,pos[i]-pos[i-1]-sz);
		cout<<ans<<endl;
	}
	return 0;
}