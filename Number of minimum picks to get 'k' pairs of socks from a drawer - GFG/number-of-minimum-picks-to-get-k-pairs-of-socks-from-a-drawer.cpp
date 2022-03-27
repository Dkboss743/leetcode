// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int find_min(int a[], int n, int k) {
        // Your code geos here
        int tot_pairs = 0;
        int tot_socks = 0;
        int max_pairs = 0;
        for(int i=0 ; i<n ; i++){
            tot_pairs += a[i]/2;
            if(a[i]&1){
                max_pairs += (a[i]-1)/2;
            }
            else{
                max_pairs += (a[i]-2)/2;
            }
            tot_socks += a[i];
        }
        //  cout << max_pairs << endl;
        if(tot_pairs < k){
            return -1;
        }
       
        else if(k<=max_pairs)
        return (2*(k-1) + n + 1);
        else{
            return 2*max_pairs + n + k-max_pairs;       }
        
        
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> k;
        Solution obj;
        cout << obj.find_min(a, n, k) << endl;
    }
    return 1;
}
  // } Driver Code Ends