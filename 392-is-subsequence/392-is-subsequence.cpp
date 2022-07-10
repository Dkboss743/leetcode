class Solution {
public:
    bool isSubsequence(string s, string t) {
        int start_s = 0;
        int start_t = 0;
        while(start_s < s.size() && start_t < t.size()){
            if(s[start_s] == t[start_t]){
                start_s++;
            }
            start_t++;
        }
        return start_s == s.size();
        
    }
};