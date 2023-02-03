class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        map<int, string> mp;
        int l = 0;
        bool down = true;
        for(int i = 0 ; i<n; i++){
            mp[l] += s[i];
            l == 0 ? down = true : l == numRows -1 ? down = false : down;
           
            down ? l++ : l--; 
        }
        string ans = "";
        for(auto x : mp){
            ans += x.second;
        }
        return ans;
    }
};