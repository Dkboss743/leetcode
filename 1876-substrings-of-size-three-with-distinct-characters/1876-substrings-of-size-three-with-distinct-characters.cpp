class Solution {
public:
    bool check(string s){
        unordered_set<char> st;
        for(auto x : s){
            if(st.find(x) != st.end()){
                return false;
            }
            st.insert(x);
        }
        return true;
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