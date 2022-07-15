class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int n = coins.size();
      int dp[amount+1];
      dp[0] = 0;
      for(int i=1; i<=amount; i++){
          dp[i] = INT_MAX;
      }
      for(int i=1; i<=amount; i++){
          for(int j=0; j<n; j++){
              if(coins[j] <=i){
                  int temp = dp[i-coins[j]];
                  if(temp!=INT_MAX && temp+1 < dp[i]){
                      dp[i] = temp+1;
                  }
              }
          }
      }
        if(dp[amount] == INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};