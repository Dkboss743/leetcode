class Solution {
public:
   int countConsistentStrings(string allowed, vector<string>& words) {
       bool s = true;
       int ans = 0;
        for(int i = 0; i<words.size(); i++){
            s = true;
            for(auto c : words[i]){
                if(allowed.find(c) == string::npos) {
                    s = false;
                    break;
                }
            }
            if(s) ans++;
        }
        return ans;
    }
};