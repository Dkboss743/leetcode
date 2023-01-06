class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int temp = INT_MAX;
        int ans = 0;
        for(int i = 0 ;i < prices.size() ; i++){
            temp = min(temp , prices[i]);
            ans = max(ans , prices[i] - temp);
        }
        return ans;
        
    }
};