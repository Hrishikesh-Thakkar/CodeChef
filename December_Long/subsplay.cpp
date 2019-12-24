#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	map<char,int> prev_occ;
	for(int i = 97;i<=122;i++){
	    char c = i;
	    prev_occ[c] = -1;
	}
	int n;
	string s;
	cin>>n>>s;
	
	int ans = 0;
	for(int i=0;i<n;i++){
	    if(prev_occ[s[i]]!=-1){
	        //Update Answer Step
	        ans = max(ans,(prev_occ[s[i]]+1+(n-1-i)));
	    }
	    prev_occ[s[i]] = i;
	}
	cout<<ans<<endl;
	prev_occ.clear();
	}
	return 0;
}
