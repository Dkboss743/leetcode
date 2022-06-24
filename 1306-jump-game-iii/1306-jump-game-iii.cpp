class Solution {
public:
    int canR(vector<int> &arr , int start , vector<vector<int>>&dp){
        if(start < 0 || start >=arr.size()){
            return -1;
        }
        if(arr[start] == 0){
                return 1;
        }
        if(dp[start][1] == 1){
            return dp[start][0];
        }
        dp[start][1] = 1;
        dp[start][0] = canR(arr,start - arr[start] , dp);
        if(dp[start][0] == 1)
            return dp[start][0];
        return dp[start][0] = canR(arr , start + arr[start], dp);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<vector<int>> dp(arr.size(),vector<int>(2,-1));
        int val = canR(arr,start,dp);
        return (val == 1);
       
    }
};