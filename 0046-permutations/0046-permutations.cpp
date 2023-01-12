class Solution {
public:
    set<vector<int>> ans;
    set<int> ind;
    void util(vector<int> &nums , vector<int> temp){
        if(temp.size() == nums.size()){
            ans.insert(temp);
        }
        for(int i=0; i<nums.size() ; i++){
            if(ind.find(i) == ind.end()){
            temp.push_back(nums[i]);
            ind.insert(i);
            util(nums , temp);
            ind.erase(i);
            temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        util(nums, {});
        vector<vector<int>>val;
        for(auto x : ans){
            val.push_back(x);
        }
        return val;
    }
};