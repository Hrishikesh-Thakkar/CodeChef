#include<bits/stdc++.h>
using namespace std;

long long int ncr(int n,int k){
if (n < k) {
		return 0;
	} else if (n == 0 || k == 0 || k == n) {
		return 1;
	}
	if (k > n - k)  k = n - k;

	 long long result = 1;
	for ( int d = 1; d <= k; ++d) {
		result *= n--;
		result /= d;
	}

	return result;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		long long int ans=1;
		map<int,int> m;
		map<int,int> ma;
		set<int> s;
		for(int i=0;i<n;i++)
			m[a[i]]++;
		for(int i=0; i<k;i++)
			{s.insert(a[i]); ma[a[i]]++;}
		set <int, int> :: iterator i;
		for(i=s.begin();i!=s.end();i++)
			ans*=ncr(m[*i],ma[*i]);
		cout<<ans<<endl;
	}
	return 0;
}