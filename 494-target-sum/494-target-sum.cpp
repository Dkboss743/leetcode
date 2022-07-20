class Solution {
public:
    unordered_map<string,int> dp;
    int util(vector<int> &nums , int target , int ind){
        if(ind == nums.size()){
            if(target == 0){
                return 1;
            }
            return 0;
        
        }
        string key = to_string(ind) +" " + to_string(target);
        
        if(dp.find(key)!=dp.end()){
            return dp[key];
        } 
        return dp[key] = util(nums,target+nums[ind],ind+1) +  util(nums,target-nums[ind],ind+1);
     
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return util(nums,target,0);
        
    }
};