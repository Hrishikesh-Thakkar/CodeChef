#include<bits/stdc++.h>
using namespace std;

int lef = 1;
int righ;
void binarySearch(int l, int r) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        char c,c2;
        cout<<mid<<endl;
        cin>>c; 
        if (c == 'E') exit(0); 
        cout<<mid<<endl;
        cin>>c2;
        if(c==c2){
	        if (c=='L') {
	        	righ = mid-1;
	        	binarySearch(lef, righ); 
	        } 
	        if (c=='G') {
	        	lef = mid+1;
	         	binarySearch(lef, righ);
	     	} 
        }
        else{
        	binarySearch(l,mid-1); 
        	binarySearch(mid+1,r);
        }
    } 
} 
int main(){
	ios_base::sync_with_stdio(false);
	int n; cin>>n;
	righ = n;
	binarySearch(lef,righ);
	return 0;
}