class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int>mp;
        for(auto x : s){
            mp[x]++;
        }
        int n = s.size();
        stack<char> st;

        vector<bool>vis(26,false);
        for(int i=0; i<n; i++){
            mp[s[i]]--;
            if(vis[s[i]-'a']){
                continue;
            }
                while(!st.empty() && st.top() > s[i] && mp[st.top()]>0){
                    vis[st.top()-'a'] = false;
                    st.pop();
               }
                st.push(s[i]);
                vis[s[i]-'a'] = true;
            }
        string ans = "";
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};