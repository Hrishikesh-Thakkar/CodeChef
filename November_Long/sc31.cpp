#include<bits/stdc++.h>
using namespace std;

char xore(char a, char b){
	if(a == '0'&& b == '0')
		return '0';
	else if(a == '1' && b == '1')
		return '0';
	else 
		return '1';
}
int main(){

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		string s1;
		for(int i = 1;i<n;i++)
		{
			cin>>s1;
			for(int j = 0 ; j < 10; j++)
				s[j] = xore(s[j],s1[j]);
		}
	  int count = 0;
	  for(int i = 0; i<10;i++)
	  	if(s[i] == '1')
	  		count++;
	  cout<<count<<endl;
	}
	return 0;
}