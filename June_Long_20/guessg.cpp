#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	char c = 'Q';
	int n; cin>>n;
	int low_odd = 1, high_odd = n, low_even = 0, high_even = n;
	int i = 0;
	while(c!='E'){
		if(i%2==0){
			int mid = low_odd + (high_odd - low_odd)/2;
			cout<<mid<<endl;
			cin>>c;
			if(c=='E') exit(0);
			else if(c=='G'){
				low_odd = mid+1;
			}
			else if(c=='L'){
				high_odd = mid-1;
			}
		}
		else{
			int mid = low_even + (high_even - low_even)/2;
			cout<<mid<<endl;
			cin>>c;
			if(c=='E') exit(0);
			else if(c=='G'){
				low_even = mid+1;

			}
			else if(c=='L'){
				high_even = mid-1;
			}
		}
		i++;
	}
	exit(0);
	return 0;
}