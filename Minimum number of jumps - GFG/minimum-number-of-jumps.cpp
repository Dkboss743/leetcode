// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int maxJump = INT_MIN;
        int curJump = arr[0];
        int ans = 0;
        if(n == 1){
            return 0;
        }
        for(int i=0; i<n ;i++){
            maxJump = max(maxJump,arr[i]+i);
            if(curJump < i){
                return -1;
            }
            if(curJump > n){
                return ans+1;
            }
            if(i == curJump){
                curJump = maxJump;
                ans++;
            }
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
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends