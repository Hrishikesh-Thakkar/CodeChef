#include<bits/stdc++.h>
using namespace std;

int sumDigit(int a){
	int ans = 0;
	while(a>0){
		ans+=a%10;
		a/=10;
	}
	return ans;
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int a[n],b[n];
		//0 chef wins
		//1 morty wins
		//2 draw
		int chef = 0; int morty = 0;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i];
			int suma = sumDigit(a[i]);
			int sumb = sumDigit(b[i]);
			if(suma>sumb) chef++;
			else if(suma<sumb) morty++;
			else{
				chef++; morty++;
			}
		}
		if(chef>morty) cout<<0<<" "<<chef<<endl;
		else if(chef<morty) cout<<1<<" "<<morty<<endl;
		else cout<<2<<" "<<chef<<endl;
	}
	return 0;
}