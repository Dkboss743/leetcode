class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        ans[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            ans[i] = ans[i+1] + nums[i];
        }
        int pivot_index = -1;
        int val = 0;
        for(int i = 0; i<n; i++){
           if(ans[i]-nums[i] == val){
               pivot_index = i;
               break;
           }
           val+=nums[i];
        }
        return pivot_index;
        
    }
};