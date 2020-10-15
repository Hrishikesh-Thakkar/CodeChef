#include<bits/stdc++.h>
using namespace std;

int check(char a,char b){
//if same axis return 0; else return 1;
	if(a=='L'){if(b=='L' || b=='R') return 0;}
	if(a=='R'){if(b=='L' || b=='R') return 0;}
	if(a=='U'){if(b=='U' || b=='D') return 0;}
	if(a=='D'){if(b=='U' || b=='D') return 0;}
	return 1;
}
int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int x=0,y=0;
		if(n==0) cout<<0<<" "<<0<<endl;
		else{
			if(s[0]=='L')
				x--;
			else if(s[0]=='R')
				x++;
			else if(s[0]=='U')
				y++;
			else if(s[0]=='D')
				y--;
			 //cout<<x<<" "<<y<<endl;
			for(int i=1;i<n;i++){
				if(check(s[i],s[i-1])==0)
					x+=0;
				else if(s[i]=='L')
					x--;
				else if(s[i]=='R')
					x++;
				else if(s[i]=='U')
					y++;
				else if(s[i]=='D')
					y--;
			}
			cout<<x<<" "<<y<<endl;
		}
		
	}
	return 0;
}