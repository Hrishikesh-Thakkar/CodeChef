#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int f[n+1],p[n+1];
		for(int i=1;i<=n;i++)
			cin>>f[i];
		for(int i=1;i<=n;i++)
			cin>>p[i];
		map<int,int> ma;
		map<int,int> exists;
		for(int i=1;i<=n;i++)
			exists[f[i]] = 1;
		for(int i=1;i<=n;i++){
			ma[f[i]]+=p[i];
		}
		int mini = 1e9;
		for(int i=1;i<=m;i++){
			if(exists[i] == 1){
				mini = min(mini,ma[i]);
			}
		}
		cout<<mini<<endl;
	}
	return 0;
}