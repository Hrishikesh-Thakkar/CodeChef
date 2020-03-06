#include<bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int goals_a = 0, goals_b = 0;
		int counter_a = 0 , counter_b = 0;
		int i;
		for( i=0;i<2*n;i++){
			if(i%2==0 && s[i]=='1')
				{goals_a++;}
			if(i%2==1 && s[i]=='1')
				{goals_b++;}
			if(i%2==0) counter_a++; else counter_b++;
			//cout<<goals_a<<" "<<goals_b<<" "<<n-counter_b<<endl;
			if(goals_a>goals_b+(n-counter_b))
				{cout<<i+1<<endl; break;}
			else if(goals_b>goals_a+(n-counter_a))
				{cout<<i+1<<endl; break;}
		}
		if(i==2*n)
			cout<<2*n<<endl;
	}
	return 0;
}