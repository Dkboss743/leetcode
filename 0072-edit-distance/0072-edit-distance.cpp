class Solution {
public:
    vector<vector<int>> dp;
    int util(string word1, string word2, int n , int m){
        if(n==0){
            return m;
        }
        if(m == 0){
            return n;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(word1[n-1] == word2[m-1]){
            return dp[n][m] = util(word1, word2, n-1, m-1);
        }
        return dp[n][m] = min(util(word1 , word2 , n-1 , m) , min(util(word1, word2, n-1, m-1) , util(word1, word2, n, m-1)))+1;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp = vector<vector<int>>(n+1 , vector<int>(m+1, -1));
        return util(word1,word2 ,n , m);
    }
};