class Solution {
public:
    set<vector<int>> ans;
    void util(vector<int> &nums, int i , vector<int> &temp){
        if(temp.size() > 1){
            ans.insert(temp);
        }
        for(i; i<nums.size() ; i++){
            if(temp.size() == 0 || nums[i] >= temp[temp.size() - 1]){
                temp.push_back(nums[i]);
                util(nums , i+1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        util(nums , 0 , temp);
        vector<vector<int>> val;
        for(auto x : ans){
            val.push_back(x);
        }
        return val;
    }
};