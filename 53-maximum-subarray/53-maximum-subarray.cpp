class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start = 0;
        int max_so_far = INT_MIN;
        for(int i=0 ; i<nums.size(); i++){
            start = start+nums[i];
            if(start > max_so_far){
                max_so_far = start;
            }
            if(start < 0){
                start = 0;
            }
        }
        return max_so_far;
    }
};