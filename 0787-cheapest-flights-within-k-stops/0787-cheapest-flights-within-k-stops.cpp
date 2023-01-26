class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<pair<int,int>>> gr;
    int dst;
    int dfs(int src , int k){
        if(src == dst){
            return 0;
        }
        if(k <= 0){
            return INT_MAX;
        }
        if(dp[src][k]!= -1){
            return dp[src][k];
        }
        int temp = INT_MAX;
        for(int i = 0; i<gr[src].size() ; i++){
           int val = dfs(gr[src][i].first , k-1);
            if(val != INT_MAX){
                temp = min(temp , val+gr[src][i].second);
            }
        }
        return dp[src][k] = temp;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        gr.resize(n); 
        for(int i = 0 ; i<flights.size(); i++){
           gr[flights[i][0]].push_back({flights[i][1] , flights[i][2]});
        }
        this->dst = dst;
        dp = vector<vector<int>>(n+1, vector<int>(k+2 , -1));
        int ans = dfs(src , k+1);
        return ans == INT_MAX ? -1 : ans;
        
    }
};