#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long n,p;
		cin>>n>>p;
		long a[n];
		for(int i=0;i<n;i++){cin>>a[i];}
		int check_one = 0; int check_two = 0;
		long pos_one = -1; long pos_two = -1;
		for(int i=0;i<n;i++)
			if(p%a[i]!=0){
				pos_one = i;
				check_one = 1;
				break;
			}
		for(int i=1;i<n;i++)
			if(a[i]%a[i-1]!=0){
				check_two = 1;
				pos_two = i;
				break;
			}
		if(check_one==0 && check_two==0){
			cout<<"NO"<<endl;
		}
		else if(check_one == 1){
			cout<<"YES"<<" ";
			for(int i = 0;i<n;i++){
				if(i!=pos_one){
					cout<<0<<" ";
				}
				else{
					cout<< p/a[i] + 1<<" ";
				}
			}
			cout<<endl;
		}
		else if(check_two==1){
			cout<<"YES"<<" ";
			for(int i=0;i<n;i++){
				if(i == pos_two-1){
					long num = p - a[pos_two];
					cout<<(num/a[i])+1<<" ";
				}
				else if(i == pos_two){cout<<1<<" ";}
				else{cout<<0<<" ";}
			}
			cout<<endl;
		}
	}
return 0;
}