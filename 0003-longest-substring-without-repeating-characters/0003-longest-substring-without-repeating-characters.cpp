class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int j = 0;
        unordered_map<char, int> mp;
        int ans = 0;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
            while(mp[s[i]] > 1){
                mp[s[j]]--;
                j++;
            }
            ans = max(ans , i-j+1);
        }
        return ans;
    }
};