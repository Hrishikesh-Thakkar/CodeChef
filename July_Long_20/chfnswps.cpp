#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	long long int t;
	cin>>t;
	while(t--){
		long long int n; cin>>n;
		long long int a[n],b[n];
		unordered_map<long long int,long long int> combined_map;
		unordered_map<long long int,long long int> a_map;
		unordered_map<long long int,long long int> b_map;
		vector<long long int> missing_a;
		vector<long long int> missing_b;
		long long int mini = INT_MAX;
		for(long long int i=0;i<n;i++) {cin>>a[i];combined_map[a[i]]++; a_map[a[i]]++; mini = min(a[i],mini);}
		for(long long int i=0;i<n;i++) {cin>>b[i];combined_map[b[i]]++; b_map[b[i]]++; mini = min(b[i],mini);}
		long long int flag = 0;
		for(auto it:combined_map){
			if(it.second%2){
				flag = 1;
				break;
			}
			long long int diff_a = it.second/2 - a_map[it.first];
			if(diff_a>0){
				for(long long int i=0;i<diff_a;i++) missing_a.push_back(it.first);
			}
			long long int diff_b = it.second/2 - b_map[it.first];
			if(diff_b>0){
				for(long long int i=0;i<diff_b;i++) missing_b.push_back(it.first);
			}
		}
		sort(missing_a.begin(),missing_a.end());
		sort(missing_b.begin(),missing_b.end());
		if(flag){
			cout<<-1<<endl;
		}
		else{
			long long int ans = 0;
			for(long long int i=0;i<missing_a.size();i++){
				ans+=min(min(missing_a[i],missing_b[missing_b.size()-1-i]),2*mini);
			}
			cout<<ans<<endl;
		}

	}
	return 0;
}