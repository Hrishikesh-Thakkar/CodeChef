#include <iostream> 
#include <stack> 
#include <vector>
#include <stdlib.h> 
using namespace std; 

int flag = 1;
vector<vector<pair<long long,long long>>> cvx_hll;
typedef long long ull;  
struct Point 
{ 
    ull x, y; 
}; 
  
Point p0; 
  
pair<Point,int> secondElement(stack<pair<Point,int>> &S) 
{ 
    pair<Point,int> p = S.top(); 
    S.pop(); 
    pair<Point,int> res = S.top(); 
    S.push(p); 
    return res; 
} 
  
int swp(Point &p1, Point &p2) 
{ 
    Point temp = p1; 
    p1 = p2; 
    p2 = temp; 
} 
  
ull dist(Point p1, Point p2) 
{ 
    return (p1.x - p2.x)*(p1.x - p2.x) + 
          (p1.y - p2.y)*(p1.y - p2.y); 
} 
int orient(Point p, Point q, Point r) 
{ 
    ull val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
int compare(const void *vp1, const void *vp2) 
{ 
   Point *p1 = (Point *)vp1; 
   Point *p2 = (Point *)vp2; 
  
   int o = orient(p0, *p1, *p2); 
   if (o == 0) 
     return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1; 
  
   return (o == 2)? -1: 1; 
} 

int inside(vector<vector<pair<long long,long long>>> cvx_hll, Point c)
{
  int ans = 0;
  for(int j = 0;j<cvx_hll.size();j++)
  {
    vector<pair<long long,long long>> res = cvx_hll[j];
    for(int i=res.size()-1;i>0;i--)
   {
    Point p1,p2;
    p1.x = res[i].first;
    p1.y = res[i].second;
    p2.x = res[i-1].first;
    p2.y = res[i-1].second;
    // p2 = res[i-1];
    if(orient(p1,c,p2)!=1)
      {
        return ans; 
      }  
   }

   Point p1,p2;
    p2.x = res[res.size()-1].first;
    p2.y = res[res.size()-1].second;
    p1.x = res[0].first;
    p1.y = res[0].second;
   if(orient(p1,c,p2)!=1)
      {
        return ans; 
      }
      ans++;
}
return ans;
}
  
vector<pair<long long,long long>> hull(Point points[], ull n, Point c) 
{ 
    vector<pair<long long,long long>> res, temp;
    vector<int> mask(n,1); 
   ull ymin = points[0].y, min = 0; 
   for (int i = 1; i < n; i++) 
   { 
     ull y = points[i].y; 
  
     if ((y < ymin) || (ymin == y && 
         points[i].x < points[min].x)) 
        ymin = points[i].y, min = i; 
   } 
   swp(points[0], points[min]); 
  
   p0 = points[0]; 
   qsort(&points[1], n-1, sizeof(Point), compare); 
  
   int m = 1; // Initialize size of modified array 
   vector<Point> store;
  m = n;
  
   if (m < 3) return res; 
  
   stack<pair<Point,int>> S; 
   S.push(make_pair(points[0],0)); 
   S.push(make_pair(points[1],1)); 
   S.push(make_pair(points[2],2));

   if(orient(points[0],c,points[1])!=1) 
   {
    return res;
   } 
  
   for (int i = 3; i < m; i++) 
   { 
      while (orient(secondElement(S).first, S.top().first, points[i]) == 1) 
         S.pop();

      S.push(make_pair(points[i],i)); 
   } 
  
   while (!S.empty()) 
   { 
       pair<Point,int> p = S.top(); 
       res.push_back(make_pair(points[p.second].x, points[p.second].y));
       mask[p.second] = 0;
       S.pop(); 
   } 
   for(int i=res.size()-1;i>0;i--)
   {
    Point p1,p2;
    p1.x = res[i].first;
    p1.y = res[i].second;
    p2.x = res[i-1].first;
    p2.y = res[i-1].second;
    if(orient(p1,c,p2)!=1)
      {
        return temp; 
      }  
   }

   Point p1,p2;
    p2.x = res[res.size()-1].first;
    p2.y = res[res.size()-1].second;
    p1.x = res[0].first;
    p1.y = res[0].second;
   if(orient(p1,c,p2)!=1)
      {
        return temp; 
      }

   for(int i=0;i<m;i++)
    if(mask[i]==1)
      temp.push_back(make_pair(points[i].x,points[i].y));
    for(int i=0;i<store.size();i++)
      temp.push_back(make_pair(store[i].x,store[i].y));
  if(temp.size()==0)
    flag = 0;
   return temp;
} 

vector<pair<long long,long long>> hull1(Point points[], ull n) 
{ 
    vector<pair<long long,long long>> res, temp;
    vector<int> mask(n,1);
   ull ymin = points[0].y, min = 0; 
   for (int i = 1; i < n; i++) 
   { 
     ull y = points[i].y; 
  
     if ((y < ymin) || (ymin == y && 
         points[i].x < points[min].x)) 
        ymin = points[i].y, min = i; 
   } 
  
   swp(points[0], points[min]); 
  
   p0 = points[0]; 
   qsort(&points[1], n-1, sizeof(Point), compare); 
  
   int m = 1; 

   vector<Point> store;
  m = n;
  
   if (m < 3) return res; 
  
   stack<pair<Point,int>> S; 
   S.push(make_pair(points[0],0)); 
   S.push(make_pair(points[1],1)); 
   S.push(make_pair(points[2],2));

   for (int i = 3; i < m; i++) 
   { 
      while (orient(secondElement(S).first, S.top().first, points[i]) == 1) 
         S.pop();

      S.push(make_pair(points[i],i)); 
   }

   if(orient(points[0], points[m-1], points[m-2])==0)
   {
    S.push(make_pair(points[m-2],m-2)); 
    int j=m-3;
    while (m>=0 && orient(secondElement(S).first, S.top().first, points[j]) == 0)   
    { S.push(make_pair(points[j],j));
      j--;
    }
   }
  
   while (!S.empty()) 
   { 
       pair<Point,int> p = S.top(); 
       res.push_back(make_pair(points[p.second].x, points[p.second].y));
       mask[p.second] = 0;
       S.pop(); 
   } 
   cvx_hll.push_back(res);
   
   for(int i=0;i<m;i++)
    if(mask[i]==1)
      temp.push_back(make_pair(points[i].x,points[i].y));
    for(int i=0;i<store.size();i++)
      temp.push_back(make_pair(store[i].x,store[i].y));
  if(temp.size()==0)
    flag = 0;
   return temp;
} 
int main() 
{ 
    int t;
    cin>>t;

    while(t--)
    {
      ull n,q;
      cvx_hll.clear();
      cin>>n>>q;

      Point temp[n];
      for(int i=0;i<n;i++)
      {
        cin>>temp[i].x>>temp[i].y;
      }

      int n1 = n;
      Point pts[n];
        for(int i=0;i<n;i++)
          pts[i] = temp[i];

      do{
          flag = 1;
          Point t[n1];
          for(int i=0;i<n1;i++)
            t[i] = pts[i];
        vector<pair<long long,long long>> res;
          res = hull1(t, n1); 
          for(int i=0;i<res.size();i++)
          {
              pts[i].x = res[i].first;
              pts[i].y = res[i].second;
          }
          n1 = res.size();
        }while(n1!=0);
      while(q--)
      {
        Point c;
        cin>>c.x>>c.y;
        int ans = inside(cvx_hll,c);
        cout<<ans<<endl;
      }
    }
    return 0; 
} 