class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mn = INT_MAX;
        int mn_sum = 0;
        int mx_sum = 0;
        int mx = INT_MIN;
        int tot = accumulate(nums.begin() , nums.end() , 0);
        for(int i = 0; i<nums.size() ; i++){
            mn_sum += nums[i];
            mx_sum += nums[i];
            mx = max(mx , mx_sum);
            mn = min(mn , mn_sum);
            if(mx_sum < 0){
                mx_sum = 0;
            }
            if(mn_sum > 0){
                mn_sum = 0;
            }
        }
        if(tot - mn == 0){
            return mx;
        }
        return max(tot - mn , mx);
    }
};