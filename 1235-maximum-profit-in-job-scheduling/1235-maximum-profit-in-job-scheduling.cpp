class Solution {
public:
    vector<int> dp;
    int util(vector<int> &startTime, vector<vector<int>> &jobs , int index){
      int n  = startTime.size();
      if( index >= n ){
          return  0;
      }
      if(dp[index]!=-1){
          return dp[index];
      }
      int a = util(startTime, jobs , index+1);
      int next = lower_bound(startTime.begin() , startTime.end() , jobs[index][1]) - startTime.begin();
      int b = util(startTime , jobs , next) + jobs[index][2];
      return dp[index] = max(a , b);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = startTime.size();
        for(int i=0; i<n ;i++){
            jobs.push_back({startTime[i], endTime[i] , profit[i]});
        }
        sort(jobs.begin() , jobs.end());
        sort(startTime.begin(), startTime.end());
        dp = vector<int>(n,-1);
        return util(startTime, jobs, 0);
        
    }
};