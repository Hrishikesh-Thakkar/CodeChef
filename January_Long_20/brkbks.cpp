#include<bits/stdc++.h>
using namespace std;

int main(){

int t;
cin>>t;
while(t--){
	int s,a,b,c;
	cin>>s>>a>>b>>c;
	int ans = 0;		
	if(a>c)
	{
		int temp = a;
		a = c;
		c = temp;
	}
	if(s>=a+b+c)
		ans = 1;
	else if(s>=a+b)
		ans = 2;
	else 
		ans = 3;
	
	cout<<ans<<endl;
}
return 0;
}