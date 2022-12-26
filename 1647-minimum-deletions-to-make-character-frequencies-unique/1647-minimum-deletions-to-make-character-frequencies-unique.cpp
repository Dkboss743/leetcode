class Solution {
public:
    int minDeletions(string s) {
        unordered_set<int> st;
        unordered_map<char, int> mp;
        for(auto x : s){
            mp[x]++;
        }
        vector<int> vt;
        for(pair<char, int> p: mp){
            vt.push_back(p.second);
        }
        int ans = 0;
        sort(vt.begin() , vt.end() ,greater<int>());
        for(auto ele : vt){
            int temp = 0;
            int freq = ele;
            while(freq > 0 && st.find(freq) != st.end()){
                freq--;
                temp++;
            }
            st.insert(freq);
            ans+=temp;
        }
        return ans;
        
    }
};