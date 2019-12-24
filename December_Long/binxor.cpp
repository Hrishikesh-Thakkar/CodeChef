#include<bits/stdc++.h>
using namespace std;

const int Maxn = 1e5 + 1, Mod = 1e9 + 7;
int fact[Maxn];
int ifact[Maxn];
int inv[Maxn];
template<typename T, typename T1>
T mod(T x, T1 p) {
    x %= p;
    if (x < 0)
        x += p;
    return x;
}
 
// x must be relatively prime to p
template<typename T>
T inverse(T x, T p) {
    x = mod(x, p);
    if (x == 1)
        return x;
    return mod(1LL * (-p / x) * (inverse(p % x, p)) , p);
}
int NcR(int n, int r) {
    int ret = (1LL * ifact[n - r] * ifact[r]) % Mod ;
    ret = (1LL * ret * fact[n]) % Mod;
    return ret;
}
int main() {
    // your code goes here
    fact[0] = 1;
    for(int i = 1; i < Maxn; i++) {
        fact[i] = 1LL * fact[i - 1] * i % Mod;
    }
   
    ifact[0] = 1;
    for(int i = 1; i < Maxn; i++) {
        ifact[i] = 1LL * ifact[i - 1] * inverse(i, Mod) % Mod;
    }
    
    int t;
    cin>>t;
    while(t--){
        int n;
        string a,b;
        cin>>n>>a>>b;
        unsigned long long int a_zeros = 0,b_zeros = 0, a_ones = 0, b_ones = 0;
    unsigned long long int xor_zeros=0,xor_ones=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='0')
            a_zeros++;
         if(b[i]=='0')
            b_zeros++;
    }
    
    a_ones = n - a_zeros;
    b_ones = n - b_zeros;
    xor_zeros = min(a_zeros,b_zeros) + min(b_ones,a_ones);
    xor_ones = n-xor_zeros;
    unsigned long long int k = min(a_zeros,b_ones)+ min(b_zeros,a_ones);
    unsigned long long ans = 0;
    for(int i = xor_ones; i<=k ;i+=2){
        ans = (ans + NcR(n,i)) % Mod;
            }
    cout<<ans<<endl;
        
    }
    return 0;
}
