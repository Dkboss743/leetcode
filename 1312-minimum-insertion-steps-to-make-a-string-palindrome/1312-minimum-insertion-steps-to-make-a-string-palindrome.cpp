class Solution {
public:
    vector<vector<int>> dp;
    int util(string &s, int l, int r){
        if(l>=r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        return dp[l][r] = s[l]==s[r]? util(s,l+1,r-1):(min(util(s,l,r-1) , util(s,l+1,r)) + 1);
    }
    int minInsertions(string s) {
        int n = s.size();
        dp.resize(n,vector<int>(n,-1));
        return util(s,0,n-1);
    }
};