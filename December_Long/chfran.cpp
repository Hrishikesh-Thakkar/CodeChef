#include<bits/stdc++.h>
using namespace std;

int maxn = 1e6 + 42;
int main(){
ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	int l,r;
	unordered_map<int,int> open,close;
	set<int> ends;
	int L = 1, R = 1e9;
	for(int i=0;i<n;i++){
		cin>>l>>r;
		ends.insert(l);
		ends.insert(r);
		L = max(L,l);
		R = min(R,r);
		open[l]++;
		close[r]++;
	}
	int ans = n;
	int bal = 0;
	for(auto it = begin(ends); it != prev(end(ends));++it){
		bal += open[*it] - close[*it];
		if(*it >= R && L >= *next(it))
			ans = min(ans,bal);
	}
	cout<<(ans==n ? -1 : ans)<<endl;

}
return 0;
}