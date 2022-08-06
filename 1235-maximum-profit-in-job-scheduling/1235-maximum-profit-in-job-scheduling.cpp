class Solution {
public:
   
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = startTime.size();
        for(int i=0; i<n; i++){
            jobs.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        vector<int>dp(n);
        dp[0] = jobs[0][2];
        for(int i=1; i<n ;i++){
            int f = 0;
            for(int j = i-1; j>=0; j--){
                if(jobs[i][1] >= jobs[j][0]){
                    f= dp[j];
                    break;
                }
            }
            dp[i] = max(dp[i-1],f+jobs[i][2]);
        }
        return dp[n-1];
        
    }
};