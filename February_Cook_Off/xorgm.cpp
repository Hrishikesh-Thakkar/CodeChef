#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int a[n],b[n];
		for(int i=0;i<n;i++)	cin>>a[i];
		for(int i=0;i<n;i++)    cin>>b[i];
		int xor_num = 0;
		map<int,int> m;
		for(int i=0;i<n;i++)
			m[b[i]]=1;
		for(int i=0;i<n;i++)
			xor_num = xor_num ^ (a[i]^b[i]);
		int flag = 0;
		vector<int> v;
		for(int i=0;i<n;i++){
			if(m[a[i]^xor_num]==1){v.push_back(a[i]^xor_num);}
			else {flag = 1; break;}
		}
		if(flag)
			cout<<-1<<endl;
		else{for(int i=0;i<n;i++) cout<<v[i]<<" "; cout<<endl;}
	}

	return 0;
}