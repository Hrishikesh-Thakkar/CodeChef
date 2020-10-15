#include<bits/stdc++.h>
using namespace std;

int merge(string temp,string b){
    int pos = 0;
    for(int i=0;i<temp.size();i++){
        if(temp[i]<b[0]) pos = i;
        else if(temp[i]>b[0]) return i;
        else{
            int start = i;
            while(i<temp.size()&&temp[i]==b[0]) i++;
            for(int j=1;j<b.size();j++){
                if(b[j]>temp[start]) return i;
                else if(b[j]<temp[start]) return start;
            }
            return start;
        }
    }
    return pos;
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		unordered_map<char,int> m;
		for(int i=0;i<a.size();i++) m[a[i]]++;
		for(int i=0;i<b.size();i++) m[b[i]]--;
		string temp = "";
	    for(auto x: m){
	    	for(int i=0;i<x.second;i++) temp+=x.first;
	    }
	    if(temp.size()==0){
	    	cout<<b<<endl; continue;
	    }
		sort(temp.begin(), temp.end());
		if(a.size()>1000){
			int pos = merge(temp,b);
			string ans = "";
			for(int i=0;i<pos;i++) ans+=temp[i];
			ans+=b;
			for(int i=pos;i<temp.size();i++) ans+=temp[i];
			cout<<ans<<endl;
		}
		else{
			vector<string> v;
			string left = "",right = temp;
			for(int i=0;i<=temp.size();i++){
				v.push_back(left+b+right);
				left+=temp[i];
				if(right.size()!=0)
				right.erase(right.begin());
			}
			sort(v.begin(),v.end());
			cout<<v[0]<<endl;
		}
	}
	return 0;
}