// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int binSearch(vector<int> coins, int val){
        int n = coins.size();
        int low = 0;
        int high = n-1;
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(coins[mid] == val){
                return coins[mid];
            }
            else if(coins[mid] > val){
                high = mid-1;
            }
            else{
                low = mid+1;
                ans = coins[mid];
            }
        }
        return ans;
    }
    vector<int> minPartition(int N)
    {
        vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> ans;
        while(N){
            int val = binSearch(coins,N);
            N -= val;
            ans.push_back(val);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends