#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    vector<int> fib = {0,1,1,2,3,5,8,3,1,4,5,9,4,3,7,0,7,7,4,1,5,6,1,7,8,5,3,8,1,9,0,9,9,8,7,5,2,7,9,6,5,1,6,7,3,0,3,3,6,9,5,4,9,3,2,5,7,2,9,1};
    cin>>t;
    while(t--){
    long long n;
    cin>>n;
    //n =(long long int)log2(n);
    //cout<<n<<endl;
    int targetlevel = 0;
    while (n >>= 1) ++targetlevel;
    //cout<<targetlevel;
    n=pow(2,targetlevel);
    n=n%60-1;
    cout<<fib[n]<<endl;
    // cout<<fib(n,10)<<endl;
    }
    return 0;
}


