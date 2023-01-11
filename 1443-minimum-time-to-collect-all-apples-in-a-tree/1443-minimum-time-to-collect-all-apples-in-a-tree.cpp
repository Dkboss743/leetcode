class Solution {
public:
    vector<vector<int>> tree;
    int dfs(int ind , vector<bool> &hasApple , int par = -1 , int ans = 0){
        for(auto to  : tree[ind]){
            if(to!=par){
                ans += dfs(to, hasApple , ind);
            }
        }
        return (!ind) ? ans : (hasApple[ind] || ans) ? ans + 2 : 0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        tree.resize(n);
        for(auto x : edges){
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        return dfs(0 , hasApple);
    }
};