class Solution {
public:
    int longestPalindromeSubseq(string s) {
      int n = s.size();
      int dp[n][n];
        memset(dp, 0 , sizeof(dp));
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        for(int i=n-1; i>=0; i--){
            for(int j = i+1; j<n ; j++){
                if(s[j] == s[i]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
             }
        }
        return dp[0][n-1];
    }
};