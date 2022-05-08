// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void toBst(vector<int>&ans,vector<int> &nums,int low,int high){
        if(low>high)
        return;
        int mid  = low + (high-low)/2;
        ans.push_back(nums[mid]);
        toBst(ans,nums,low,mid-1);
        toBst(ans,nums,mid+1,high);
            
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high  = n-1;
        vector<int> ans;
        toBst(ans,nums,low,high);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends