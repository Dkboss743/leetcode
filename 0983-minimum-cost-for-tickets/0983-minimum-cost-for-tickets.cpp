class Solution {
public:
int helper(vector<int>& days,vector<int>& costs,int dateCanTravel,int idx,int n,vector<int>&dp){
        if(idx>=n){
            return 0;
        }
        if(dateCanTravel>=days[idx]){
            return helper(days,costs,dateCanTravel,idx+1,n,dp);  
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int a=costs[0]+helper(days,costs,days[idx],idx+1,n,dp);
        int b=costs[1]+helper(days,costs,days[idx]+6,idx+1,n,dp);
        int c=costs[2]+helper(days,costs,days[idx]+29,idx+1,n,dp);

        return dp[idx]=min({a,b,c});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n,-1);
        int ans=helper(days,costs,0,0,n,dp);
        return ans;
    }
};