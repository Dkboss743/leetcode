// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<int> data;
        for(auto y : x){
           if(y == '[' || y== '(' || y== '{'){
           data.push(y);
           }
           else if(!data.empty()){
               if(y==']' && data.top()=='[')
                   data.pop();
               else if(y==')' && data.top() == '(')
               data.pop(); 
               else if (y=='}' && data.top() == '{')
               data.pop();
               else 
               return false;
           }
           else
           return false;
        }
        return data.empty();
        // Your code here
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends