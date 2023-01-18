class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mn = INT_MAX;
        int sum = 0;
        int mx = INT_MIN;
        int ans = INT_MIN;
        int cnt = 0;
        int tot = accumulate(nums.begin() , nums.end() , 0);
        for(int i = 0; i<nums.size() ; i++){
            if(nums[i] < 0) {
                cnt++;
            }
            sum += nums[i];
            mx = max(mx , sum);
            if(sum < 0){
                sum = 0;
            }
        }
        if(cnt == nums.size()){
            return *max_element(nums.begin() , nums.end());
        }
        sum = 0;
        for(int i = 0; i<nums.size() ; i++){
            sum += nums[i];
            mn = min(mn , sum);
            if(sum > 0){
                sum = 0;
            }
        }
        ans = max(tot - mn , mx);
        return ans;
    }
};