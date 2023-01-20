class Solution {
public:
    set<vector<int>> ans;
    void util(vector<int> &nums, int i , vector<int> &temp){
        if(temp.size() > 2){
            ans.insert(vector(temp.begin() + 1 , temp.end()));
        }
        for(i; i<nums.size() ; i++){
            if(nums[i] >= temp[temp.size() - 1]){
                temp.push_back(nums[i]);
                util(nums , i+1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp = {-108};
        util(nums , 0 , temp);
        vector<vector<int>> val;
        for(auto x : ans){
            val.push_back(x);
        }
        return val;
    }
};