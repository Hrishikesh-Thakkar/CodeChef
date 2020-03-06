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
	while(t--){
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	int m1,y1,m2,y2;
	int ans = 0;
	cin>>m1>>y1>>m2>>y2;
	if(m1>2)
		y1++;
	if(m2<2)
		y2--;
	for(int i=y1;i<=y2;i++)
   		{
   		if(isLeap(i))
   			{
   				if(dayofweek(1,2,i)==6){
   					ans++;
   					v1.push_back(i);
   				}
   			}
   		else
   			{
   				if(dayofweek(1,2,i)==6 ){
   					v2.push_back(i);
   					ans++;
   				}
   				if(dayofweek(1,2,i)==0){
   					v3.push_back(i);
   					ans++;
   				}
   			}
   		}
   	cout<<ans<<endl;
   	for(int i=0;i<v1.size();i++)
   		cout<<v1[i]<<" ";
   	cout<<endl;
	   	// for(int i=0;i<v2.size();i++)
	   	// 	cout<<v2[i]<<" ";
	   	// cout<<endl;
	   	// for(int i=0;i<v3.size();i++)
	   	// 	cout<<v3[i]<<" ";

	}
	return 0;
}