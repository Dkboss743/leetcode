class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        if(n == 1){
            return true;
        }
        for(i; i>=0 ; i--){
            int j = i-1;
            while(j>=0 && j+nums[j] < i){
                j--;
            }
            if(j == 0){
                return true;
            }
            if(j == -1){
                return false;
            }
            i=j+1;
        }
        return true;
    }
};