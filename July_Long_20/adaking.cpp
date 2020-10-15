#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int k; cin>>k;
		// k is the distinct squares;
		char mat[8][8];
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				mat[i][j] = 'X';
	    mat[0][0] = 'O';
	    k--;
	    for(int i=1;i<8;i++){
	    	if(k>0){
	    		 k--;
	    		 mat[0][i] = '.';
	    	}
	    	else break;
	    }
	    for(int i=1;i<8;i++)
	    	for(int j=0;j<8;j++){
	    		if(k>0){
	    		 k--;
	    		 mat[i][j] = '.';
	    	}
	    	else break;
	    }
	   for(int i=0;i<8;i++){
	   	   	for(int j=0;j<8;j++){
	   	   		cout<<mat[i][j];
	   	   	}
	   	   	cout<<endl;
	   	}
	}
	return 0;
}