class Solution {
public:
    vector<int> ans;
    void dfs(vector<vector<int>> &tr ,int par ,int ind,string &l, unordered_map<char,int> &mp){
        int prev = mp[l[ind]];
        for(auto to : tr[ind]){
            if(to == par){
                continue;
            }
            dfs(tr , ind , to , l , mp);
        }
        ans[ind] = ++mp[l[ind]] - prev;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n , 0);
        unordered_map<char, int> mp;
        vector<vector<int>> tr(n);
        for(auto x : edges){
            int fr = x[0];
            int to = x[1];
            tr[x[0]].push_back(x[1]);
            tr[x[1]].push_back(x[0]);
        }
        dfs(tr , -1, 0 , labels , mp);
        return ans;
    }
};