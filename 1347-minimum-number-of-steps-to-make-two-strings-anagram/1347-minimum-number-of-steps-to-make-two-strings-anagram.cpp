class Solution {
public:
    int minSteps(string s, string t) {
        int mp[27] = {0};
        for(int i=0; i<s.size() ; i++){
            mp[s[i]-'a']++;
            mp[t[i]-'a']--;
        }
        int cnt = 0;
        for(auto x : mp){
            if(x > 0){
                cnt+=x;
            }
        }
        return cnt;
    }
};