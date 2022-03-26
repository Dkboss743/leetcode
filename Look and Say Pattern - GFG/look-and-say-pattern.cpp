// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        if (n == 1)
      return "1";
    if (n == 2)
      return "11";
    string a = lookandsay(n - 1);
    string ans = "";
    int cnt = 1;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == a[i + 1]) {
        cnt++;
      } else {
        ans += to_string(cnt) + a[i];
        cnt = 1;
      }
    }
    return ans;
        
        // code here
    }   
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends