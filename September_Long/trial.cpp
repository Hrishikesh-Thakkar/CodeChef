#include<iostream> 
#include<cmath> 
 
using namespace std;

int fib(int n) { 
  double phi = (1 + sqrt(5)) / 2; 
  return round(pow(phi, n) / sqrt(5)); 
} 
  
// Driver Code 
int main () 
{ 
  int t;
  cin>>t;
  while(t--){
  long long int n;
  cin>>n; 
  if(n==1)
  	cout<<0<<endl;
  else
  	cout<<(int)log2(n)%10<<endl;
}
  return 0; 
} 