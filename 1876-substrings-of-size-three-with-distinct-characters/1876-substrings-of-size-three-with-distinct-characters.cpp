class Solution {
public:
    bool check(string s){
        set<char> st;
        for(int i = 0; i<s.size() ; i++){
            st.insert(s[i]);
        }
        return st.size() == s.size();
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