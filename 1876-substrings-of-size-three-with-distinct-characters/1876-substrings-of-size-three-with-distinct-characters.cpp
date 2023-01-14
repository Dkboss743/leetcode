class Solution {
public:
    bool check(string s){
        if(s[0] != s[1] && s[0] !=s[2] && s[1]!=s[2]){
            return true;
        }
        return false;
    }
    int countGoodSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i<n-2; i++){
            string temp = s.substr(i,3);
            if(check(temp)){
                ans++;
            }
        }
        return ans;
    }
};