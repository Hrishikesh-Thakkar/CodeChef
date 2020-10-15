#include<bits/stdc++.h>
using namespace std;

int diamonds(int num){
	int even_sum = 0,odd_sum = 0;
	while(num>0){
		int digit = num%10;
		num/=10;
		if(digit%2) odd_sum+=digit;
		else even_sum+=digit;
	}
	return abs(even_sum - odd_sum);
}
int main(){
	int t; cin>>t;
	int sizes = 2e6+1;
	vector<long long int> prefix(sizes,0);
	for(int i=1;i<sizes;i++)
		prefix[i] = prefix[i-1] + diamonds(i);
	vector<long long int> dp(sizes,0);
	dp[1] = 2;
	for(int i=2;i<1e6+1;i++){
		dp[i] = dp[i-1] + prefix[2*i] + prefix[2*i-1] - 2*prefix[i];
	}
	while(t--){
		int num; cin>>num;
		cout<<dp[num]<<endl;
	}
	return 0;
}