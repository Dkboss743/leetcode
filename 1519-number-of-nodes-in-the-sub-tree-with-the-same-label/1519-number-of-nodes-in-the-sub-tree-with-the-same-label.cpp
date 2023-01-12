class Solution {
public:
    vector<int> ans;
    void dfs(vector<vector<int>> &tr ,int par ,int ind,string &l, vector<int> &mp){
        int prev = mp[l[ind]-'a'];
        for(auto to : tr[ind]){
            if(to != par){
              dfs(tr , ind , to , l , mp); 
            }
        }
        ans[ind] = ++mp[l[ind]-'a'] - prev;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n , 0);
        vector<int>mp(26, 0);
        vector<vector<int>> tr(n);
        for(auto x : edges){
            tr[x[0]].push_back(x[1]);
            tr[x[1]].push_back(x[0]);
        }
        dfs(tr , -1, 0 , labels , mp);
        return ans;
    }
};