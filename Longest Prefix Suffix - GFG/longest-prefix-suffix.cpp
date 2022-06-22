// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:
    
	int lps(string s) {
	    int n =s.size();
	    
	    vector<int>data(n,0);
	    int i=1;
	    int len=0;
	    data[0] = 0;
	    while(i<n){

	         if(s[i]==s[len]){
	            data[i] = len+1;
	            len++;
	            i++;
	         }
	         else{
	             if(len!=0){
	                 len = data[len-1];
	             }
	             else{
	                 data[i] = 0;
	                 i++;
	             }
	         }
	        
	    }
	    return data[n-1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends