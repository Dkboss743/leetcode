class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int st = 0;
       vector<int> ans(2,-1);
       int en = nums.size()-1;
        while(st <= en){
            int mid = st + (en - st)/2;
            if(nums[mid] == target){
                en = mid-1;
                ans[0] = mid;
            }
            else if(nums[mid] > target){
                en = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        st = 0;
        en = nums.size()-1;
        while(st <= en){
            int mid = st + (en-st)/2;
            if(nums[mid] == target){
                st = mid+1;
                ans[1] = mid;
            }
            else if(nums[mid] > target){
                en = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }
};