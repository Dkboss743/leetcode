class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> ans(1<<16,0);
        for(auto x : nums)
            for(auto y: nums)
                ans[x&y]++;
        int count = 0;
        for(auto x : nums)
            for(int i=0; i<(1<<16) ; i++){
                if((i&x) == 0){
                    count+= ans[i];
                }
            }
        return count;
    }
};