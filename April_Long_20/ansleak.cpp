#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t; cin>>t;

	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int a[n][k];
		for(int i=0;i<n;i++){
			for(int j=0;j<k;j++){
				cin>>a[i][j];
			}
		}
		int worse_case = 1e9;
		int best_worse_case = -1;
		int pos = -1;
		for(int i=0;i<k;i++){
			for(int j=i+1;j<k;j++){
				int counter = 0;
				if(i==j) continue;
				for(int l=0;l<n;l++){
					if(a[l][i]!=a[l][j]) counter++;
				}
				worse_case = min(counter,worse_case);
			}
			if(best_worse_case<worse_case) pos = i;
			best_worse_case = max(worse_case,best_worse_case);
		}
		for(int i = 0; i<n; i++) cout<<a[i][pos]<<" ";
		cout<<endl;
	}
	return 0;
}