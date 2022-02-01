class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>ans;
        for(int i = 0 ; i<k ; i++)
            ans.push(nums[i]);
        int size = nums.size();
        for(int i = k ; i<size ; i++){
            if(nums[i]>ans.top()){
                ans.pop();
                ans.push(nums[i]);
            }
        }
        return ans.top();
    }
};