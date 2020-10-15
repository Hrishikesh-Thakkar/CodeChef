#include<bits/stdc++.h>
using namespace std;

//10 Points Partial
unordered_map<string,unsigned long long int> str_power;
unsigned long long int mod = 998244353;

unsigned long long int  getRepeats(string s,int weights[26]){
	unsigned long long int ans = 0;
	unsigned long long int local_ans = 0;
	string r = "";
	for(int i=1;i<=s.size();i++){
		r+=s[i-1];
		local_ans+=weights[s[i-1]-'a'];
		int end = s.size()-(s.size()%r.size());
		int flag = 0,flag1 = 0;
		if(end==s.size()) {flag1 = 1;}
		else{
			string prefix = s.substr(end,s.size()%r.size());
			if(r.substr(0,prefix.size())==prefix) {
				flag1=1;
			}
		}
		if(flag1){
			for(int j=0;j<end-r.size()+1;j+=r.size()){
			if(s.substr(j,r.size())!=r){
				flag = 1;
				break;
			}
		}
		if(!flag){
			ans+=local_ans;
			}
		}
	}
	return ans;
}
unsigned long long int power(unsigned long long int x, unsigned long long int y, unsigned long long int m) 
{ 
    if (y == 0) 
        return 1; 
    unsigned long long int p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
unsigned long long int modulo_inverse(unsigned long long int denom){
	return power(denom,mod-2,mod);
}
int main(){
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--){
		str_power.clear();
		string s; cin>>s;
		int weights[26]; for(int i=0;i<26;i++) cin>>weights[i];
		unordered_map<string,unsigned long long int> freq;
		int n = s.size();
        for (int i = 0; i < n; i++){ 
	        char temp[n - i + 1]; 
	        int tempindex = 0; 
	        for (int j = i; j < n; j++){ 
	            temp[tempindex++] = s[j]; 
	            temp[tempindex] = '\0'; 
	            string target = temp;
	            freq[target]++;
            	if(freq[target]==1) str_power[target] = getRepeats(target,weights);
	        } 
    	}
        unsigned long long int a = n,b=n+1;
        if(a%2==0) a/=2;
        else b/=2;
        unsigned long long int denom = a*b;
        unsigned long long int numer = 0;
         for (auto it = freq.begin(); it != freq.end(); it++) {
        	numer+=(str_power[it->first]*(it->second));
        }
        unsigned long long int bottom = modulo_inverse(denom);
        bottom%=mod;
        numer%=mod;
        cout<<(bottom*numer)%mod<<endl;
	}
	return 0;
}