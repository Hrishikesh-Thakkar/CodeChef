#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,q;
	cin>>n>>q;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	while(q--){
		int l,r;
		cin>>l>>r;
		l--; r--;
		int inc=0,dec=0;
		if(a[l]<a[l+1]) inc++;
		if(a[r]>a[r-1]) inc++;
		if(a[l]>a[l+1]) dec++;
		if(a[r]<a[r-1]) dec++;

		if(inc==dec)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}	
	return 0;
}