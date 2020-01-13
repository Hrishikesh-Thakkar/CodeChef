#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	int d;
	string s;
	while(t--){
		cin>>d;
		cin>>s;

		int present=0,absent;
		for(int i=0;i<d;i++)
			if(s[i]=='P')
				present++;
		absent=d-present;
        if(d<=4)
		    {
		        if(ceil(0.75*d-present)<=0)
		            cout<<0<<endl;
		        else
		            cout<<-1<<endl;
		    }
		  
	 else if(ceil(0.75*d-present)<=0)
			cout<<0<<endl;
		else {
			int proxy=0;
			for(int i=2;i<s.size()-2;i++)
			{
				if(s[i]=='A')
				{
					if((s[i-2]=='P'||s[i-1]=='P')&&(s[i+1]=='P'||s[i+2]=='P'))
					proxy++;
				}
			
			}
			if(ceil(0.75*d-present)<=proxy)
				cout<<ceil(0.75*d-present)<<endl;
			else cout<<-1<<endl;

		}

	}
}