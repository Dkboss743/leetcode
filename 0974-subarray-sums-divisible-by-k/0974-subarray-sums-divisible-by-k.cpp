class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;
        int ans = 0;
        int sum = 0;
        for(int i = 0;i <nums.size() ; i++){
            sum += nums[i];
            int md = (sum% k + k)%k;
            if(mp.find(md) != mp.end()){
                ans += mp[md];
            }
            mp[md]++;
        }
        return ans;
    }
};