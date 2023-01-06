class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto x: s){
            mp[x]++;
        }
        int temp = 0;
        for(auto x : mp){
            temp += x.second%2;
        }
        return s.size()-temp+ (temp>0);
    }
};