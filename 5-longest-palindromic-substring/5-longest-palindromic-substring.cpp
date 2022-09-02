class Solution {
public:
    bool isPalindrome(string a){
        int start = 0;
        int end = a.size()-1;
        
        while(start <= end){
            if(a[start] == a[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string str = "";
        str+=s[0];
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[j] == s[i]){
                    if(j-i == 1 || dp[i+1][j-1]){
                        dp[i][j] = 1;
                        if(j-i+1 > str.size()){
                            str = s.substr(i,j-i+1);
                        }
                    }
                }
            }
        }
        return str;
    }
};