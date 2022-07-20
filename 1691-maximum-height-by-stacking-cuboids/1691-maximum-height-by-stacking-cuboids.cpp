class Solution {
public:
    static bool canStack(vector<int> &a , vector<int> &b){
        return a[1]<=b[1] && a[2]<=b[2];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &x : cuboids){
            sort(x.begin() , x.end());
        }
        int n = cuboids.size();
        vector<int> dp(n);
        sort(cuboids.begin(),cuboids.end());
        for(int i=0; i<n; i++){
            int temp = 0;
            dp[i] = cuboids[i][2];
            for(int j=0; j<i; j++){
                if(canStack(cuboids[j],cuboids[i])){
                    temp = max(temp,dp[j]);
                }
            }
         dp[i]+=temp;
        }
        return *max_element(dp.begin(),dp.end());
    }
};