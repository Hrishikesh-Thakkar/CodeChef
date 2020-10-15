#include<bits/stdc++.h>
using namespace std;

int binary(long long int arr[],int low,int high,long long int key){
    if(low<=high){
      int mid = low + (high-low)/2;
      if(arr[mid]==key) return -1;
      else if(arr[mid]<key) return binary(arr,mid+1,high,key);
      else return binary(arr,low,mid-1,key);
    }
    return low;
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    long long int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    int q; cin>>q;
	    while(q--){
	        long long int x,y;
	        cin>>x>>y;
	        x+=y;
	        if(x<a[0]) cout<<0<<endl;
	        else if(x>a[n-1]) cout<<n<<endl;
	        else{
	            int pos = binary(a,0,n-1,x);
	            cout<<pos<<endl;
	        }
	    }
	}
	return 0;
}
