// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    
    string smallestWindow (string s, string p)
    {
       unordered_map<char,int> unit;
       for(auto x : p){
           unit[x]++;
       }
       int length = unit.size();
       int n = s.size();
       string val = "";

       int j = 0;
       int i=0;
       int ans = INT_MAX;
       
       while(j<n){
           if(unit.find(s[j])!=unit.end()){
               unit[s[j]]--;
               if(unit[s[j]] == 0)
               length--;
           }
             while(length == 0){
             if(j-i+1 < ans){
                 ans= j-i+1;
                 val = s.substr(i,ans);
             }
            
             if(unit.find(s[i])!=unit.end()){
                 unit[s[i]]++;
                 if(unit[s[i]] == 1)
                 length++;
             }
             i++;
           }
           j++;
           
       }
       
       return ans!=INT_MAX? val : "-1";
       
      
       
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends