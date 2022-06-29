class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto itr = unique(nums.begin() , nums.end());
        nums.resize(distance(nums.begin(),itr));
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return nums[1];
        }
        return nums[nums.size()-3];
    }
};