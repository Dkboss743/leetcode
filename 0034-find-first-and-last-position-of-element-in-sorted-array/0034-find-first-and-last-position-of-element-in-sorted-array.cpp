class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       
       vector<int> ans(2,-1);
       int loop = 2;
       while(loop--){
        int st = 0;
        int en = nums.size()-1;
        while(st <= en){
            int mid = st + (en - st)/2;
            if(nums[mid] == target){
                loop == 1 ? en = mid-1 : st = mid+1;
                ans[1-loop] = mid;
            }
            else if(nums[mid] > target){
                en = mid-1;
            }
            else{
                st = mid+1;
            }
        }
       }
        return ans;
    }
};