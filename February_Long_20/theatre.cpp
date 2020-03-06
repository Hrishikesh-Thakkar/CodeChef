#include<bits/stdc++.h>
using namespace std;
 
 
 
long long cost(int j, vector<int> tic, vector<int> ind, vector<vector<int> > arr)
{
    if(j==4)
    {
        return 0;
    }
    else
    {
        long long ans = INT_MIN;
        int flag = 0;
        int count = 0;
        for(int i=0;i<4;i++)
        {
            flag = 0;
            for(int k=0;k<ind.size();k++)
                if(ind[k]==i)
                {
                    flag = 1;
                    count++;
                    break;
                }
           if(flag)
                continue;
            vector<int> temp = ind;
            temp.push_back(i);
            if(arr[i][j]!=0)
                ans = max(ans,tic[j]*arr[i][j] + cost(j+1,tic,temp,arr));
        }
        // if(count==4)
        //     ans =
        ans = max(ans,cost(j+1,tic,ind,arr)-100);
        //cout<<ans<<endl;
        return ans;
    }
}
 
int main()
{
               int t;
               cin>>t;
              
               unordered_map<int,int> umap;
               umap[12] = 0;
               umap[3] = 1;
               umap[6] = 2;
               umap[9] = 3;
               long long count = 0;
 
               for(int i=0;i<t;i++)
               {
                              long long ans = INT_MIN;
                              int n;
                              cin>>n;
                              vector<vector<int> > arr;
       
        for(int j=0;j<4;j++)
        {
            vector<int> temp;
            for(int k=0;k<4;k++)
                temp.push_back(0);
            arr.push_back(temp);
        }
 
                              for(int j=0;j<n;j++)
                              {
                                             char a;
                                             int b;
 
                                             cin>>a>>b;
                                            
                                             //cout<<a-65<<" "<<umap[b]<<endl;
 
                                             arr[a-65][umap[b]]++;
                              }
 
                              vector<int> tic = {25,50,75,100};
                              vector<int> ind;
                             
                              do {
            ans = max(ans,cost(0,tic,ind,arr));
            //cout<<ans<<" \n";
            // for(int j=0;j<4;j++)
            //     cout<<tic[j]<<" ";
        } while (next_permutation(tic.begin(), tic.end()));
                             
                              cout<<ans<<endl;
                              count+=ans;
               }
              
               cout<<count<<endl;
}