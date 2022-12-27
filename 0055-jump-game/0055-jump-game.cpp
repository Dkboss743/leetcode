class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        
        for(i; i>0 ; i--){
            int j = i-1;
            while(j>=0 && j+nums[j] < i){
                j--;
            }
            i=j+1;
        }
        return i==0;
    }
};