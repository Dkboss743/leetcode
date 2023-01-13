class Solution {
public:
    vector<vector<int>> gr;
    int ans;
    int dfs(string &s , int idx , int par){
        int curr = 0;
        for(int i = 0;i <gr[idx].size() ; i++){
            if(gr[idx][i] != par){
                int temp = dfs(s, gr[idx][i] , idx);
                if(s[gr[idx][i]] == s[idx]){
                    temp = 0;
                }
                    ans = max(ans , curr + temp + 1);
                    curr = max(curr , temp);
                }
            }
        return curr+1;
    }
        
    int longestPath(vector<int>& parent, string s) {
        ans = 1;
        gr.resize(s.size());
        if(parent.size() == 1){
            return 1;
        }
        for(int i = 1; i<parent.size() ; i++){
            gr[parent[i]].push_back(i);
            gr[i].push_back(parent[i]);
        }
        dfs(s, 0 , -1);
        return ans;
    }
    
};