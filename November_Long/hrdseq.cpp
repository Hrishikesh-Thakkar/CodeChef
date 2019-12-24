#include<bits/stdc++.h>
using namespace std;

int main(){


    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        map<int,int> count;
        a[0]=0;
        count[0]=1;
        for(int i = 1; i < n ; i++){
            if(count[a[i-1]] == 1){
                a[i] = 0;
                count[0]++;
            }
            else{
                int j;
                for(j = i-2; j >= 0; j--)
                    if(a[j] == a[i-1])
                        break;
                    a[i] = i-1-j;
                    count[a[i]]++;
            }
        }
        cout<<count[a[n-1]]<<endl;
    }
    return 0;
}