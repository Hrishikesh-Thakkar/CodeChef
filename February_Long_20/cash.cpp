#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
	    long long int n,k;
		cin>>n>>k;
	    long long int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		vector<long long int> v;
		for(int i=0;i<n;i++)
			if(a[i]%k!=0)
				v.push_back(a[i]%k);
		int len = v.size();
		if(len == 0){
			cout<<0<<endl;
		}
		else{
		long long int pos[len];
		long long int neg[len]; 
		pos[0] = v[0];
		neg[0] = k-v[0];
		for(int i=1;i<len;i++){
			pos[i] = pos[i-1] + v[i]; 
			neg[i] = neg[i-1] + (k-v[i]);
		}
		long long int ans = pos[len-1];
		for(int i=0;i<len;i++){
			if(pos[i]>=(neg[len-1]-neg[i]))
				ans =min(ans,pos[i] - (neg[len-1]-neg[i]));
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}