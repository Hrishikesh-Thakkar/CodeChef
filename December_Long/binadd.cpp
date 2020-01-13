#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){
		string a,b;
		cin>>a>>b;
		reverse(begin(a), end(a));
		reverse(begin(b), end(b));
		while(a.size() < b.size()) a += "0";
		while(b.size() < a.size()) b += "0";
		a += "0"; b += "0";
		int carry = 0, ans = 0, cur = 0;
		for(int i=0;i<a.size();i++){
			carry = carry + (a[i]-'0') + (b[i]-'0');
			if(carry==2)
				cur++;
			else
				cur = carry/2;
			carry/=2;
			ans = max(ans,cur+1);
		}
		cout<<ans *(b.find('1')!= string::npos)<<endl;
		
	}
	return 0;
}