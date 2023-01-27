class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<n ; i++){
            if(i > 0 &&  nums[i] == nums[i-1]) continue;
            int st = i+1;
            int en = n-1;
            while(st < en){
                if(nums[i] + nums[st] + nums[en] > 0){
                    en--;
                }
                else if(nums[i] + nums[st] + nums[en] < 0){
                    st++;
                }
                else{
                    vector<int> temp = {nums[i] , nums[st] , nums[en]};
                    ans.push_back(temp);
                    st++;
                }
            }
        }
        sort(ans.begin() , ans.end());
        ans.erase(unique(ans.begin() , ans.end()) , ans.end());
       
        return ans;
    }
};