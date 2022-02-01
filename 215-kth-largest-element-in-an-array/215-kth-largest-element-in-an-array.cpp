class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>ans;
         int size = nums.size();
        for(int i = 0 ;i<size ; i++)
            ans.push(nums[i]);
        while(k>1)
        {
            ans.pop();
            k--;
        }
        return ans.top();
    }
};