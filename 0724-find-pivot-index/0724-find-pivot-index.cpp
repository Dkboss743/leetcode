class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);
        int val = 0;
        int ind = -1;
        int prev = 0;
        for(int i = 0; i<n; i++){
            if((sum - nums[i]) == (2*prev)){
                ind = i;
                break;
            }
            prev+=nums[i];
        }
        return ind;
    }
};