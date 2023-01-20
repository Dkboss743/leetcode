class Solution {
public:
    set<vector<int>> ans;
    void util(vector<int> &nums, int i , vector<int> &temp){
        if(temp.size() > 1){
            ans.insert(temp);
        }
        for(int k = i; k<nums.size() ; k++){
            if(temp.size() == 0 || nums[k] >= temp[temp.size() - 1]){
                temp.push_back(nums[k]);
                util(nums , k+1, temp);
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