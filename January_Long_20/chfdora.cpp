#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		long long int a[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				{
					cin>>a[i][j];
				}
		}
		long long int ans = n*m;
		for(int i=1;i<n-1;i++){
			for(int j=1;j<m-1;j++){
				int left = j-1;
				int right = j+1;
				int top = i-1;
				int bottom = i+1;

				while(left>=0 && right<m && top>=0 && bottom<n){
					if((a[i][left]==a[i][right])&&(a[bottom][j]==a[top][j])) {
						ans++;
						left--;
						right++;
						top--;
						bottom++;
					}
					else break;
				}
			}
		}
	cout<<ans<<endl;
	}
	return 0;
}