#include<bits/stdc++.h>

using namespace std;
int main()

{
                unsigned long long int t;
                cin>>t;
                for(unsigned long long int i=0;i<t;i++)

                {
                                unsigned long long int n;
                                cin>>n;
                                vector<unsigned long long int> arr(n),arr1(n);
                                for(unsigned long long int j=0;j<n;j++)
                                {
                                                cin>>arr[j];
                                                arr1[j] = abs(arr[j]%4);

                                } 

                                vector<unsigned long long int> sub;
                                unordered_map<unsigned long long int, vector<unsigned long long int> > umap;
                                unsigned long long int flag = 0;
                                unsigned long long int len = 0;
                                unsigned long long int present = 0;
                                unsigned long long int num;
                                for(unsigned long long int j=0;j<n;j++)
                                {
                                                if(arr1[j]%2==1)
                                                {
                                                                if(flag==0)
                                                                {
                                                                                flag = 1;
                                                                }
                                                                len++;
                                                }
                                                else if(arr1[j]==2)
                                                {
                                                               
                                                                if(flag==0)
                                                                {
                                                                                num = j;
                                                                                flag = 1;
                                                                                present = 1;

                                                                }
                                                                else if(present==0)
                                                                {
                                                                                num = j;
                                                                                umap[num].push_back(len+1);
                                                                                sub.push_back(len+1);
                                                                                len = 0;
                                                                                present = 1;
                                                                }
                                                                else
                                                                {
                                                                                umap[num].push_back(len+1);
                                                                    			sub.push_back(len+1);
                                                                                sub.push_back(len+1);
                                                                                num = j;
                                                                                umap[num].push_back(len+1);
                                                                                len = 0;
                                                                }
                                                }
                                                else
                                                {
                                                                if(flag==1)
                                                                {
                                                                                if(present==1)
                                                                                {
                                                                                                present = 0;
                                                                                                flag = 0;
                                                                                                umap[num].push_back(len+1);
                                                                                                sub.push_back(len+1);
                                                                                                len = 0;

                                                                                }
                                                                                else
                                                                                {
                                                                                                flag = 0;
                                                                                                len = 0;
                                                                                }

                                                               }
 
                                                }

                                }

                                if(flag==1)

                                {

                                                if(present==1 && len!=0)

                                                {

                                                                umap[num].push_back(len+1);

                                                                sub.push_back(len+1);

                                                }

                                }
                                unordered_map<unsigned long long int, vector<unsigned long long int> >::iterator it;

                                unsigned long long int res = 0;

 

                                for(it = umap.begin(); it!=umap.end(); it++)

                                {

                                               

                                                vector<unsigned long long int> temp = it->second;

                                                if(temp.size()==1)

                                                {

                                                                res += temp[0];

                                                }

                                                else

                                                {

                                                                res += (temp[0]-1)*(temp[1]-1) + temp[0] + temp[1] -1;

                                                }

                                }

                                unsigned long long int ans = (n*(n+1)/2) - res;
                                cout<<ans<<endl;

                }

}