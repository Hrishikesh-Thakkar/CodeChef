#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		 cin>>a[i];
	int ans = 1;
	int mini = a[0];
	for(int i = 1;i<=4;i++){
	if(a[i]<mini)
		{ans++; mini=a[i];}
		}
	for(int i=5;i<n;i++){
		mini = a[i-1];
		mini = min(a[i-2],mini);
		mini = min(a[i-3],mini);
		mini = min(a[i-4],mini);
		mini = min(a[i-5],mini);
		if(a[i]<mini){
			ans++;
		}
	}
	cout<<ans<<endl;
	}
	return 0;
}