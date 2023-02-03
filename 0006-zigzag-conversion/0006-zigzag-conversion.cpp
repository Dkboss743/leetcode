class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        map<int, string> mp;
        int l = 0;
        bool down = true;
        for(int i = 0 ; i<n; i++){
            mp[l] += s[i];
            if(l == 0){
                down = true;
            }
            else if(l == numRows-1){
                down = false;
            }
            down ? l++ : l--; 
        }
        string ans = "";
        for(auto x : mp){
            // cout << x.second << endl;
            ans += x.second;
        }
        return ans;
    }
};