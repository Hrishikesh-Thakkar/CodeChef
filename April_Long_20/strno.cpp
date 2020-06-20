#include<bits/stdc++.h>
using namespace std;

int totalPrimes(int n){
	int ans = 0;
	while (n % 2 == 0)  
    {  
        ans++;  
        n = n/2;  
    } 
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            ans++; 
            n = n/i;  
        }  
    }  
     
    if (n > 2)  
        ans++; 
    return ans;
}
int main(){

	int t;
	cin>>t;
	int x,k;
	while(t--){
		cin>>x>>k;
		int prime = totalPrimes(x);
		if(k>=x) cout<<0<<endl;
		else if(k==1){
			if(x==1) cout<<0<<endl;
			else cout<<1<<endl;
		}
		else{
			if(prime>=k){cout<<1<<endl;}
			else cout<<0<<endl;
		}
		
	}
	return 0;
}