class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
        int mini  = INT_MAX;
        int maxo = INT_MIN;
        for(int i=0 ; i<n ; i++){
            mini = min(mini,prices[i]);
            maxo = max(maxo,(prices[i] - mini));
        }
        return maxo;
    }
};