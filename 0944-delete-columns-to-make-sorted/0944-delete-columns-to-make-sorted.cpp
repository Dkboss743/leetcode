class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int j = 0;
        int ans = 0;
        for(int i = 0; i<m; i++){
            j = 0;
            while(j<n-1){
                if(strs[j][i] > strs[j+1][i]){
                    ans++;
                    break;
                }
                j++;
            }
        }
        return ans;
    }
};