class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> val = strs;
        for(auto &x : val){
            sort(x.begin(), x.end());
        }
        map<string,vector<int>> data;
        for(int i=0; i<strs.size() ; i++){
            data[val[i]].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto stri : data){
            vector<int> temp = stri.second;
            vector<string> val_ans;
            for(auto x : temp){
                val_ans.push_back(strs[x]);
            }
            ans.push_back(val_ans);
        }
        return ans;
    }
};