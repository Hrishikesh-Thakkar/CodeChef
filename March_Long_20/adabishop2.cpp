#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int r,c;
	    cin>>r>>c;
	    if(r!=1 || c!=1){
	       cout<<27<<endl;
	       cout<<(r+c)/2<<" "<<(r+c)/2<<endl;
	       cout<<1<<" "<<1<<endl;
	       
	    }
	    else{
	        cout<<25<<endl;
	    }
	    
	    cout<<2<<" "<<2<<endl;
	    cout<<1<<" "<<3<<endl;
	    cout<<3<<" "<<1<<endl;
	    cout<<2<<" "<<2<<endl;
	    cout<<3<<" "<<3<<endl;
	    cout<<1<<" "<<5<<endl;
	    cout<<5<<" "<<1<<endl;
	    cout<<3<<" "<<3<<endl;
	    cout<<4<<" "<<4<<endl;
	    cout<<1<<" "<<7<<endl;
	    cout<<7<<" "<<1<<endl;
	    cout<<4<<" "<<4<<endl;
	    cout<<5<<" "<<5<<endl;
	    cout<<2<<" "<<8<<endl;
	    cout<<8<<" "<<2<<endl;
	    cout<<5<<" "<<5<<endl;
	    cout<<6<<" "<<6<<endl;
	    cout<<4<<" "<<8<<endl;
	    cout<<8<<" "<<4<<endl;
	    cout<<6<<" "<<6<<endl;
	    cout<<7<<" "<<7<<endl;
	    cout<<8<<" "<<6<<endl;
	    cout<<6<<" "<<8<<endl;
	    cout<<7<<" "<<7<<endl;
	    cout<<8<<" "<<8<<endl;
	}
	return 0;
}
