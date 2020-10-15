#include <iostream> 
using namespace std; 

unsigned int numberOfSetBits(int i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		long long int even = 0;
		long long int odd = 0;
		for(int i=0;i<n;i++){
			if(numberOfSetBits(a[i])%2==0)
				even++;
		}
		odd = n - even;
		while(q--){
			int p; cin>>p;
			int isOdd = 0,isEven = 0;
			if(numberOfSetBits(p)%2==0) isEven = 1;
			else isOdd = 1;
			if(isOdd == 1)
				cout<<odd<<" "<<n-odd<<"\n";
			else
				cout<<even<<" "<<n-even<<"\n";
		}
	}
	return 0;
}