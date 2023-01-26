class Solution {
public:
    int dfs(vector<vector<pair<int,int>>> &gr, int src , int dst , int k,vector<vector<int>> &dp){
        if(src == dst){
            return 0;
        }
        if(k <= -1){
            return INT_MAX;
        }
        if(dp[src][k]!= -1){
            return dp[src][k];
        }
        int temp = INT_MAX;
        for(int i = 0; i<gr[src].size() ; i++){
           int val = dfs(gr , gr[src][i].first , dst , k-1, dp);
            if(val != INT_MAX){
                temp = min(temp , val+gr[src][i].second);
            }
        }
        return dp[src][k] = temp;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> gr(n); 
        for(int i = 0 ; i<flights.size(); i++){
           gr[flights[i][0]].push_back({flights[i][1] , flights[i][2]});
        }
        vector<vector<int>> dp(n+1, vector<int>(k+1 , -1));
        int ans = dfs(gr ,src , dst , k, dp);
        return ans == INT_MAX ? -1 : ans;
        
    }
};