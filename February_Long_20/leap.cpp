#include<bits/stdc++.h>
using namespace std;

bool isLeap(long long int year){
	if(year%4==0){
		if(year%100==0){
			if(year%400==0){
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}
int main(){
	for(int i=4;i<=1000;i+=4)
		cout<<i<<" "<<isLeap(i)<<endl;
}
