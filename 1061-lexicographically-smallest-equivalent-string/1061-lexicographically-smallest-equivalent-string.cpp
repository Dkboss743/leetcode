class Solution {
public:
    void util(unordered_map<char, set<char>> &mp , char s , char p, set<char> &st){
        if(mp.find(s)!= mp.end()){
            set<char>temp = mp[s];
            st.insert(temp.begin(),temp.end());
        }
        if(mp.find(p)!=mp.end()){
            set<char>temp = mp[p];
            st.insert(temp.begin(), temp.end());
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char , set<char>> mp;
        int n = s1.size();
        for(int i=0; i<n; i++){
            set<char> temp;
            temp.insert(s1[i]);
            temp.insert(s2[i]);
            util(mp , s1[i] , s2[i], temp);
            mp[s1[i]] = temp;
            mp[s2[i]] = temp;
        }
        string ans = "";
        for(auto &x : mp){
          set<char> temp = x.second;
          for(auto y : temp){
              temp.insert(mp[y].begin(),mp[y].end());
          }
          x.second = temp;
        }
        for(auto x : baseStr){
            if(mp.find(x) == mp.end()){
                ans += x;
            }
            else{
            ans += *(mp[x].begin());
            }
        }
        return ans;
    }
};