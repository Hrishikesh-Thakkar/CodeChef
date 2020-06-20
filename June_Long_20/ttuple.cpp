#include<bits/stdc++.h>
using namespace std;

bool collinear(long long int x1, long long int y1, long long int x2,  
               long long int y2, long long int x3, long long int y3) 
{ 
    if ((y3 - y2) * (x2 - x1) ==  
        (y2 - y1) * (x3 - x2)) 
        return true; 
    else
        return false;
} 
int ctr = 0;
bool checkZero(long long int a,long long int b,long long  int c,long long  int p,long long int q,long long int r){
	if(a==p && b==q && c==r) return true;
	return false;
}

bool checkOne(long long int a,long long int b,long long  int c,long long  int p,long long int q,long long int r){
//if 2 set 1 unset
	if(a==p && b==q) return true;
	if(a==p && c==r) return true;
	if(b==q && c==r) return true;
// if one set and two others are in ratio or sum range
	if(a==p){
		//difference 
		if(q-b==r-c) return true;
		//ratio
		if(q*c == b*r) return true; 
	}
	if(b==q){
		//difference 
		if(p-a==r-c) return true;
		//ratio
		if(p*c == a*r) return true;
	}
	if(c==r){
		//difference 
		if(q-b==p-a) return true;
		//ratio
		if(q*a == b*p) return true;
	}	
// three unset but all have same difference or ratio
	if(p-a == q-b && p-a == r-c) return true;
	if((p*b-q*a==0)&&(q*c-r*b==0)&&(p*c-r*a==0)) return true;
	return false;
}
bool common_diff(long long int a,long long int b,long long  int c,long long  int p,long long int q,long long int r){
	int diff_a = p-a;
	int diff_b = q-b;
	int diff_c = r-c;
	return checkOne(a+diff_a,b+diff_a,c+diff_a,p,q,r) || checkOne(a+diff_a,b,c+diff_a,p,q,r) || checkOne(a+diff_a,b+diff_a,c,p,q,r) ||
	 	   checkOne(a+diff_b,b+diff_b,c+diff_b,p,q,r) || checkOne(a,b+diff_b,c+diff_b,p,q,r) || checkOne(a+diff_b,b+diff_b,c,p,q,r) ||
	  	   checkOne(a+diff_c,b+diff_c,c+diff_c,p,q,r) || checkOne(a,b+diff_c,c+diff_c,p,q,r) || checkOne(a+diff_c,b,c+diff_c,p,q,r);
}
// bool common_ratio(long long int a,long long int b,long long  int c,long long  int p,long long int q,long long int r){
// 	cout<<"Im in CR"<<endl;
// 	if(a==0 || b==0 || c==0) return false;
// 	double ratio_a = 1;
// 	double ratio_b = 1;
// 	double ratio_c = 1;
// 	if(a!=0) ratio_a = p/a;
// 	if(b!=0) ratio_b = q/b;
// 	if(c!=0) ratio_c = r/c;
// 	if()
// 	return checkOne(a*ratio_a,b*ratio_a,c*ratio_a,p,q,r) || checkOne(a*ratio_a,b,c*ratio_a,p,q,r) || checkOne(a*ratio_a,b*ratio_a,c,p,q,r) ||
// 		   checkOne(a*ratio_b,b*ratio_b,c*ratio_b,p,q,r) || checkOne(a,b*ratio_b,c*ratio_b,p,q,r) || checkOne(a*ratio_b,b*ratio_b,c,p,q,r) || 
// 	       checkOne(a*ratio_c,b*ratio_c,c*ratio_c,p,q,r) || checkOne(a,b*ratio_c,c*ratio_c,p,q,r) || checkOne(a*ratio_c,b,c*ratio_c,p,q,r);
// }
bool common_diff_state(long long int a,long long int b,long long  int c,long long  int p,long long int q,long long int r){
	int diff_a = p-a;
	int diff_b = q-b;
	int diff_c = r-c;
	return checkOne(a,b,c,a,q-diff_a,r-diff_a) || checkOne(a,b,c,p-diff_b,b,r-diff_b) || checkOne(a,b,c,p-diff_c,q-diff_c,c);
}
bool common_ratio_state(long long int a,long long int b,long long  int c,long long  int p,long long int q,long long int r){
	bool val = false;
	if(a==0 || b==0 || c==0) return false;
	if(p%a==0){
		int ratio_a = p/a;

		if(ratio_a!=0 && q%ratio_a==0 && r%ratio_a == 0)
			val = val || checkOne(a,b,c,a,q/ratio_a,r/ratio_a);
	}
	if(q%b == 0){
		int ratio_b = q/b;
		if(ratio_b!=0 &&p%ratio_b==0 && r%ratio_b == 0)
			val = val || checkOne(a,b,c,p/ratio_b,b,r/ratio_b);
	}
	if(r%c==0){
		int ratio_c = r/c;
		if(ratio_c!=0 &&p%ratio_c==0 && q%ratio_c == 0)
			val = val || checkOne(a,b,c,p/ratio_c,q/ratio_c,c);
	}
	return val;
}
bool checkTwo(long long int a,long long int b,long long  int c,long long  int p,long long int q,long long int r){
	//if one tuple pair is se
	ctr = 0;
	if(a==p) return true;
	if(b==q) return true;
	if(c==r) return true;
	// if all are unset	
	//if ratios or differences match
	if(p-a==q-b) return true;
	if(p-a==r-c) return true;
	if(q-b==r-c) return true;
	if(p*b==q*a) return true;
	if(p*c==r*a) return true;
	if(q*c == b*r) return true;
	//check if collinear
	if(collinear(a,p,b,q,c,r)) {
		if(a==b && b==c){
			if(p!=q && q!=r && r!=p) return false;
		}
		return true;
	}
	// Fix one common difference or common ratio and see if the other two
	// elements can reach there in one move
	if(common_diff(a,b,c,p,q,r) || 
		// common_ratio(a,b,c,p,q,r) ||
		common_diff_state(a,b,c,p,q,r) || 
		common_ratio_state(a,b,c,p,q,r)) return true;

	return false;
}
int main(){
	int t;
	cin>> t;
	while(t--){
		long long int a,b,c;
		long long int p,q,r;
		//original tuple
		cin>>a>>b>>c;
		// expected tuple
		cin>>p>>q>>r;
		int min_moves = 3;
		bool isZero = checkZero(a,b,c,p,q,r);
		if(isZero){
			cout<<0<<endl;
			continue;
		}
		bool isOne = checkOne(a,b,c,p,q,r);
		if(isOne){
			cout<<1<<endl;
			continue;
		}
		bool isTwo = checkTwo(a,b,c,p,q,r);
		if(isTwo){
			cout<<2<<endl;
			continue;
		}
		cout<<min_moves<<endl;
	}
	return 0;
}