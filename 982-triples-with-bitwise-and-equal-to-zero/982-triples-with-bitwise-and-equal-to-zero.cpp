class Solution {
public:
    int countTriplets(vector<int>& nums) {
       unordered_map<int,int>ans;
       for(auto x: nums)
           for(auto y:nums){
               ans[x&y]++;
           }
        int cnt = 0;
        for(auto x : ans){
            for(auto y : nums){
                if((y&(x.first)) == 0 )
                    cnt+=x.second;
            }
        }
        return cnt;
    }
};