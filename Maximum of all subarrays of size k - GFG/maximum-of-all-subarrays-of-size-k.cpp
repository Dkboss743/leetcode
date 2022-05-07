// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        priority_queue<pair<int,int>>data;
        vector<int> ans;
        int i = 0;
        for(i; i<k ; i++){
            data.push({arr[i],i});
        }
        ans.push_back(data.top().first);
        for(i ; i<n ; i++){
            while(!data.empty() && (data.top().first < arr[i] || data.top().second<=(i-k))){
                data.pop();
            }
            if(data.empty()){
                ans.push_back(arr[i]);
            }
            else{
                ans.push_back(data.top().first);
            }
            data.push({arr[i],i});
        }
        return ans;
        // your code here
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends