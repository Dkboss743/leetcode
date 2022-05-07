// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
         long long getMaxArea(long long arr[], int n)
    {
        vector<int> left_big(n,0);
        vector<int> right_big(n,0);
        stack<pair<int,int>>pre;
        pre.push({0,0});
        for(int i = 1 ; i<n ; i++){
            int cnt = 0;
            while(!pre.empty() && arr[pre.top().first]>=arr[i]){
                cnt+=pre.top().second+1;
                pre.pop();
            }
            left_big[i] = cnt;
            pre.push({i,cnt});
        }
        stack<pair<int,int>>post;
        post.push({n-1,0});
        for(int i = n-2; i>=0; i--){
            int cnt = 0;
            while(!post.empty() && arr[post.top().first] >=arr[i]){
                cnt+=post.top().second+1;
                post.pop();
            }
            right_big[i] = cnt;
            post.push({i,cnt});
        }
        long long int ans = INT_MIN;
        for(int i = 0 ; i<n ; i++){
            long long int temp = (left_big[i]+right_big[i]+1)*arr[i];
            ans = max(ans,temp);
        }
        return ans;
        // Your code here
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends