class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        ans[0] = nums[0];
        for(int i = 1; i<n; i++){
            ans[i] = ans[i-1] + nums[i];
        }
        vector<int> temp(n,0);
        temp[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            temp[i] = temp[i+1] + nums[i];
        }
        int  pivot_index = -1;
        for(int i = 0; i<n; i++){
            if(ans[i]-nums[i]  == temp[i]-nums[i]){
                pivot_index = i;
                break;
            }
            
        }
        return pivot_index;
        
    }
};