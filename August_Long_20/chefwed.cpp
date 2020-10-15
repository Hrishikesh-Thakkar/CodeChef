#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n+1];
        unordered_map<int, int> ma;
        int ans = INT_MAX;
        for(int i=0;i<n;i++) cin>>a[i];
        int collisions[n+1][n+1];
        for(int i=0;i<n;i++) 
            for(int j=0;j<n;j++) collisions[i][j]=0;
        for(int i=0; i<n;i++) {
            ma.clear();
            for(int j=i;j<n;j++) {
            	if(j!=0) collisions[i][j] = collisions[i][j-1];
                if (ma[a[j]]>0) {
                    if (ma[a[j]] == 1) {
                        collisions[i][j]++;
                    }
                    collisions[i][j]++;
                }
                ma[a[j]]++;
            }
        }
        int max_tables = 100;
        int dp[101][1001];
        for(int i=0; i<=max_tables;i++) {
            for(int j=0;j<=max_tables;j++) {
                dp[i][j] = 0;
            }
        }
        for(int i=1;i<=n;i++) {
            dp[1][i] = collisions[0][i-1];
        }
        for(int i=2;i<=max_tables;i++) {
            dp[i][1]=0;
        }
        for(int i=2;i<=max_tables;i++) {
            for(int j=2;j<=n;j++) {
                int best = INT_MAX;
                for(int k=1;k<j;k++) {
                    best = min(best,dp[i-1][k]+collisions[k][j-1]);
                }
                dp[i][j] = best;
            }
        }
        for(int i=1;i<= 100;i++) {
            ans = min(i*k+dp[i][n],ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}