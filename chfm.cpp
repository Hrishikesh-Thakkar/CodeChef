#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
		unordered_map<int,int> m;
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			{
				cin>>a[i];
				if(m[a[i]]==0)
					m[a[i]]=i+1;
			}
		double sum=0;
		for(int i=0;i<n;i++)
			sum+=a[i];
		sum/=n;
		double mean=sum;
		mean*=(n-1);
		sum*=n;
		if(floor(sum-mean)!=ceil(sum-mean))
			cout<<"Impossible"<<endl;
		else if(m[sum-mean]!=0)
			cout<<m[sum-mean]<<endl;
		else
			cout<<"Impossible"<<endl;
	}
	return 0;
}