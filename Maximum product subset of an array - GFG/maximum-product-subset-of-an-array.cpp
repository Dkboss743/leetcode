// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
#define N 1000000007
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        int neg = 0;
        long long int ans = 1;
        int max_neg = INT_MIN;
        int zero = 0;
        if(n == 1){
            return a[0];
        }
        for(auto x : a){
            if(x < 0){
                neg++;
                 max_neg = max(x , max_neg);
            }
            if(x == 0)
            {
                zero++;
                continue;
               
            }
            // cout << ans << " " << x <<endl;
            ans = (ans*x)%N;
        }
        if(zero == n){
            return 0;
        }
        if(neg & 1){
            if(neg == 1 && zero > 0 && neg + zero ==n){
                return 0;
            }
            //  cout << ans << " " << max_neg <<  endl;
            ans = ans/max_neg;
        }
        return ans;
        
        
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends