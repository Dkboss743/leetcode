class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0 || n == 1)
            return n;
        vector<int> dp(n+1,0);
        dp[0] = 0;
        int ans = INT_MIN;
        dp[1] = 1;
        for(int i=2 ; i<=n; i++){
            dp[i] = i%2==0 ? dp[i/2] : dp[i/2] + dp[i/2+1];
            ans = max(ans , dp[i]);
        }
        return ans;
    }
};