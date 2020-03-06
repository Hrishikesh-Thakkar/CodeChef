#include<bits/stdc++.h>
using namespace std;


int dayofweek(int d, int m, int y)  
{  
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
}  

bool checkYear(int year) 
{ 
    return (((year % 4 == 0) && (year % 100 != 0)) || 
             (year % 400 == 0)); 
} 


int main()
{
    bool h[401]={false};
    for(int i=1;i<401;i++)
    {   
        if((dayofweek(1,2,i)==0 ||dayofweek(1,2,i)==6  )&& (!checkYear(i)) )
            h[i]=true;
        
        if(checkYear(i) && dayofweek(1,2,i)==6 )
            h[i]=true;
    }

    int t,m1,m2,y1,y2;
    cin>>t;
    while(t--)
    {   
        cin>>m1>>y1;
        cin>>m2>>y2;
        
        if(m1>2)
            y1++;
        if(m2==1)
            y2--;
        int f1=(y1/400)*101;
        int r1=y1%400;
        int f2=0;
        
        for(int i=1;i<=r1;i++)
        {
            if(h[i])f2++;
                
        }
        
        int small=f1+f2;

        int f3=(y2/400)*101;
        int r2=y2%400;
        int f4=0;
        
        for(int i=1;i<=r2;i++)
        {
            if(h[i])f4++;
                
        }
        
        bool flag =false;
       if((dayofweek(1,2,y1)==0 ||dayofweek(1,2,y1)==6  )&& (!checkYear(y1)) )
            flag=true;
        
        if(checkYear(y1) && dayofweek(1,2,y1)==6 )
            flag=true;
        
        
        int big=f3+f4;
        int ans;
        if(flag)ans=big-small+1;
        else
        ans=big-small;
        cout<<ans<<endl;
    }
    return 0;
}
  

