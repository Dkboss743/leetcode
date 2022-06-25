// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int,vector<int>,greater<int>>data;
	    for(int i=0; i<k ;i++){
	        data.push(arr[i]);
	    }
	    for(int i=k; i<n ; i++){
	        if(arr[i] > data.top()){
	            data.pop();
	            data.push(arr[i]);
	        }
	    }
	    vector<int>ans(k);
	    for(int i=k-1; i>=0; i--){
	        ans[i] = data.top();
	        data.pop();
	    }
	    return ans;
	    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends