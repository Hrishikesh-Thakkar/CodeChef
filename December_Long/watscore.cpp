#include<bits/stdc++.h>
using namespace std;

int main(){

int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	map<int,int> m;
	int a,b;
	for(int i = 0; i<n;i++)
		{
			cin>>a>>b;
			if(a>8)
				continue;
			else
				m[a] = max(m[a],b);
		}
	int ans = 0;
	for(int i=1;i<9;i++)
		ans+=m[i];
	cout<<ans<<endl;
}

return 0;
}