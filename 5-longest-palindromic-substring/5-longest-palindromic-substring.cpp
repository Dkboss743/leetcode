class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++){
            dp[i][i] = true;
        }
        string val = "";
        val+=s[0];
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[j] == s[i]){
                    if(j-i == 1 || dp[i+1][j-1]){
                        dp[i][j] = true;
                        if(j-i+1 > val.size()){
                            val = s.substr(i,j-i+1);
                        }
                    }
                }
            }
        }
        return val;
        
    }
};