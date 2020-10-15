#include<bits/stdc++.h>
using namespace std;

unsigned long long int power(unsigned long long int x, unsigned long long int y, unsigned long long int m) 
{ 
    if (y == 0) 
        return 1; 
    unsigned long long int p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
//partial -> 10 points
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n; cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    for(int i=1;i<=n;i++){
	        cout<<power(2,n-i,1e9+7)<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
