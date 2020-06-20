#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		vector<int> pos;
		for(int i=0;i<n;i++){
			int num; cin>>num;
			if(num == 1) pos.push_back(i);
		} 
		if(pos.size()<2)
			cout<<"YES"<<endl;
		else{
			int flag = 0;
			for(int i=1;i<pos.size();i++)
				if(pos[i]-pos[i-1]<6){flag = 1; break;}

			if(flag) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
	return 0;
}