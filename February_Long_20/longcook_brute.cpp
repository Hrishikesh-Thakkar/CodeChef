//longcook  brute force check

#include<bits/stdc++.h>
using namespace std;

 
bool isLeap(int year){
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

int dayofweek(int d, int m, int y)  
{  
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
}  

int main(){
	int t;
	cin>>t;
	int a[1000001];
	long long int ans = 0;
	a[0]=0;
	for(int i=1;i<=1000000;i++){
		if(isLeap(i))
   			{
   				if(dayofweek(1,2,i)==6){
   					ans++;
   				}
   			}
   		else
   			{
   				if(dayofweek(1,2,i)==6 || dayofweek(1,2,i)==0){
   					ans++;
   				}
   			}
   		a[i]=ans;
	}
	while(t--){
		int m1,y1,m2,y2;
		cin>>m1>>y1>>m2>>y2;
		if(m1>2)
			y1++;
		if(m2<2)
			y2--;
		cout<<a[y2]-a[y1-1]<<endl;
	}
	return 0;
}