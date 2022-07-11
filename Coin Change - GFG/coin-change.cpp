// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int countFull(int s[] , int m , int n,auto &lookup){
        if(n == 0){
            return 1;
        }
        if(m < 0){
            return 0;
        }
        if(n<0){
            return 0;
        }
        string key = to_string(m) + "|" + to_string(n);
        long long int res = 0;
        if(lookup.find(key) == lookup.end()){
        res += countFull(s,m-1,n,lookup) + countFull(s,m,n-s[m],lookup);
        lookup[key] = res;
        }
        return lookup[key];
    }
    
    long long int count(int S[], int m, int n) {
         unordered_map<string, long long int> lookup;
         return countFull(S,m-1,n,lookup);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends