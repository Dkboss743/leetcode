class Solution {
public:
    int minFlipsMonoIncr(string s) {
       int n = s.size();
       vector<int> ones(n , 0);
        for(int i = 1;i < n ; i++){
            ones[i] = ones[i-1] + (int)(s[i-1]=='1');
        }
        int zeros = 0;
        int ans = INT_MAX;
        for(int i = n-2; i>=0; i--){
            zeros += (int)(s[i+1] == '0');
            ans = min(ans , zeros + ones[i]);
        }
        ans = min(ans , ones[n-1] + (int)(s[n-1] == '1'));
        return ans;
    }
};