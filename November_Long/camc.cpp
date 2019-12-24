#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, m, cnt[MAXN], cnt0;
pii a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second = i%m;
		}

	sort(a,a+n);
	int ans = 2e9;
	for(int i = 0; i < m; i++) cnt[i] = 0;
	cnt0 = m;
	
	int r = 0;

	for(int l = 0; l<n ; l++){
		while(r<n && cnt0>0){
			cnt0 -= cnt[a[r].S] == 0;
			cnt[a[r++].S]++;
		}
		if(cnt0 == 0)
			ans = min(ans,a[r-1].F - a[l].F);

		cnt[a[l].S]--;
		cnt0 += cnt[a[l].S] == 0;
	}
	cout<<ans<<endl;
	}
	
	return 0;
}