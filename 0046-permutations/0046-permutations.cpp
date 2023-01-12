class Solution {
public:
    set<vector<int>> ans;
    void util(vector<int> &nums , int i){
        if(i == nums.size()-1){
            ans.insert(nums);
            return;
        }
        for(int k = i; k<nums.size(); k++){
            swap(nums[i] , nums[k]);
            util(nums , i+1);
            swap(nums[i] , nums[k]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        util(nums, 0);
        vector<vector<int>>val;
        for(auto x : ans){
            val.push_back(x);
        }
        return val;
    }
};