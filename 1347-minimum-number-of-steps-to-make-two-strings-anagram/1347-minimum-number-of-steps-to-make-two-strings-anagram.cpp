class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp;
        for(int i=0; i<s.size() ; i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        int cnt = 0;
        for(auto x : mp){
            if(x.second > 0){
                cnt+=x.second;
            }
        }
        return cnt;
    }
};