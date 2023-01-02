class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        ans[0] = nums[0];
        for(int i = 1; i<n; i++){
            ans[i] = ans[i-1] + nums[i];
        }
        int pivot_index = -1;
        int val = 0;
        for(int i = n-1; i>=0; i--){
           if(ans[i]-nums[i] == val){
               pivot_index = i;
           }
           val+=nums[i];
        }
        return pivot_index;
        
    }
};