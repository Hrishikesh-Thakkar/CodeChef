#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		string s; cin>>s;
		long ans = 0;
		for(int i=1;i<s.size();i++){
			if(s[i]!=s[i-1]){
				ans++;
				i++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}