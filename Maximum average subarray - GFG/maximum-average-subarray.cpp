// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMaxAverage(int arr[], int n, int k) {
        // code here
        int ans=0;
        int cnt = 0;
        for(int i=0; i<k ; i++){
            ans+= arr[i];
            cnt+= arr[i];
        }
        int j=0;
        int start = 0;
        // cout << ans << endl;
        for(int i=1 ; k+i-1<n ; i++){
            // cout << ans << " " << arr[j] << " " << arr[k+i-1] << endl;
            int val = cnt-arr[j] + arr[k+i-1];
            if(val>ans){
                ans = val;
                start = i;
            }
            cnt = val;
           
            j++;
        }
        return start;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxAverage(arr, n, k);
        for (int i = ans; i < ans + k; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends