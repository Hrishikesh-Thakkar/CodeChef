#include<bits/stdc++.h>
using namespace std;

int main(){

	int t; cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		string s;
		cin>>s;
		unordered_map <char,int> m;
		for(int i=0;i<n;i++) m[s[i]]++;
		while(q--){
			int ans = 0;
			int num; cin>>num;
			for(auto it = m.begin(); it!=m.end();it++ ){
				ans+=max(0,it->second-num);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}