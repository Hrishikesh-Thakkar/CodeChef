#include<bits/stdc++.h>
using namespace std;

//10 points brute force	
int main(){
	ios_base::sync_with_stdio(false);
	int n,q; cin>>n>>q;
	long long int h[n],a[n];
	for(int i=0;i<n;i++) cin>>h[i];
	for(int i=0;i<n;i++) cin>>a[i];
	while(q--){
		long long int t,b,c;
		cin>>t>>b>>c;
		b--;
		if(t==1) a[b] = c;
		else{
			c--; 
			long long int ans = a[b] + a[c];
			if(b==c) cout<<a[b]<<endl;
			else if(h[b]<=h[c]) cout<<-1<<endl;
			else if(b<c){
				long long int start = b+1;
				long long int end = c-1;
				long long int pos = -1;
				int flag = 0;
				while(pos<end && start<=end){
					pos = max_element(h+start,h+end+1)-h;
					if(h[pos]>=h[b]) {flag=1; break;}
					if(h[pos]<=h[c]) break;
					if(h[pos]==h[start-1])
						ans = ans + a[pos] - a[start-1];
					else
						ans += a[pos];
					start=pos+1;
				}
				if(flag) cout<<-1<<endl;
				else cout<<ans<<endl;
			}
			else if(b>c){
				long long int start = b-1;
				long long int end = c+1;
				long long int pos = INT_MAX-1;
				int flag = 0;
				while(pos>end && start>=end){
					pos = max_element(h+end,h+start+1)-h;
					if(h[pos]>=h[b]) {flag=1; break;}
					if(h[pos]<=h[c]) break;
					if(h[pos] == h[start+1])
						ans = ans + a[pos] - a[start+1];
					else
						ans += a[pos];
					start=pos-1;
				}
				if(flag) cout<<-1<<endl;
				else cout<<ans<<endl;
			}
		}
	}
	return 0;
}