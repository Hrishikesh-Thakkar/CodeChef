#include <bits/stdc++.h> 
using namespace std; 

int weight[100001];
int factors(long long int prod,int mod){
		int ans = 0;
		for(int i=1;i*i<=prod;i++){
				if(prod%i==0){ans = (ans+2)%mod;}
				if(i*i==prod){ans--;}
		}
		return ans;
}
void printpath(vector<int>& path) 
{ 
	long long int prod = 1;
	int mod = 1e9+7;
	for(int i = 0;i<path.size();i++){
		prod = (prod*weight[path[i]]);
	}
	cout<<factors(prod,mod)<<endl;
} 

int isNotVisited(int x, vector<int>& path) 
{ 
	int size = path.size(); 
	for (int i = 0; i < size; i++) 
		if (path[i] == x) 
			return 0; 
	return 1; 
} 

void findpaths(vector<vector<int> >&g, int src, 
								int dst, int v) 
{  	
	vector<int> path;
	queue<vector<int> > q; 
	path.push_back(src); 
	q.push(path); 
	while (!q.empty()) { 
		path = q.front(); 
		q.pop(); 
		int last = path[path.size() - 1]; 
		if (last == dst) 
			printpath(path);		 
		for (int i = 0; i < g[last].size(); i++) { 
			if (isNotVisited(g[last][i], path)) { 
				vector<int> newpath(path); 
				newpath.push_back(g[last][i]); 
				q.push(newpath); 
			} 
		} 
	} 
} 

int main() 
{ 
	int t; cin>>t;
	while(t--){
	int n; cin>>n;
	vector<vector<int> > g; 
	int v = n;  
	for(int i=0;i<n;i++){
	// construct a graph 
	int a,b; cin>>a>>b;
	g[a-1].push_back(b-1); 
	g[b-1].push_back(a-1); 
	}
	for(int i=0;i<n;i++) cin>>weight[i];
	int q; cin>>q;
	while(q--) {
	int src,dest;
	cin>>src>>dest;
	// function for finding the paths 
	findpaths(g, src, dest, v);
	}
}
	return 0; 
} 
