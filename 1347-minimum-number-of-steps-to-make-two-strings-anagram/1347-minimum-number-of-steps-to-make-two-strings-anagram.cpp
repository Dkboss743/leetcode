class Solution {
public:
    int minSteps(string s, string t) {
        int mp[26] = {0};
        int n = s.size();
        for(int i=0; i<n ; i++){
            mp[s[i]-'a']++;
            mp[t[i]-'a']--;
        }
        int cnt = 0;
        for(int i = 0 ;i<26 ; i++){
            if(mp[i] > 0){
                cnt+=mp[i];
            }
        }
        return cnt;
    }
};