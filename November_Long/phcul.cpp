#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		
		int n,m,k;
		cin>>n>>m>>k;
		
		vector<int> nx; vector<int> ny;
		vector<int> mx; vector<int> my;
		vector<int> kx; vector<int> ky;

		for(int i = 0; i < 2*n; i++)
		{
			int num,num1; cin>>num>>num1; nx.push_back(num); ny.push_back(num1);
		}

		for(int i = 0; i < 2*m; i++)
		{
			int num,num1; cin>>num>>num1; mx.push_back(num); my.push_back(num1);
		}

		for(int i = 0; i < 2*k; i++)
		{
			int num,num1; cin>>num>>num1; kx.push_back(num); ky.push_back(num1);
		}

		
	}
	return 0;
}