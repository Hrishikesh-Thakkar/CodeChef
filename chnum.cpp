#include<bits/stdc++.h>
using namespace std;

int main(){
	
int t;
cin>>t;

while(t--){
int n;
cin>>n;

int a[n];
for(int i=0;i<n;i++)
	cin>>a[i];
int pos=0;
for(int i=0;i<n;i++)
	if(a[i]>=0)
		pos++;
if(pos==n)
	cout<<n<<" "<<n<<endl;
else
	cout<<max(pos,n-pos)<<" "<<min(pos,n-pos)<<endl;
}

return 0;
}