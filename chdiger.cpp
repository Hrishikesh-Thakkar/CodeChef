#include<bits/stdc++.h>
using namespace std;

long long int maxi(long long int a,long long int b)
{
	if(a>b)
		return a;
	return b;
}

int main(){

int t;
cin>>t;

while(t--){
	long long int num;
	cin>>num;
	string s=to_string(num);
	int d;
	cin>>d;
	long long int ans;
	for(int i=0;i<s.size();i++)
		 {
		 	string s1=s;
		 	s1.erase(i);
		 	s1+=(d-'0');
		 	long long int a= stoi(s);
		 	long long int b= stoi(s1);
		 	ans=maxi(a,b);

		 }

	cout<<ans<<endl;
}
return 0;
}