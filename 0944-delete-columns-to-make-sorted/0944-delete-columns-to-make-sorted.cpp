class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for(int i = 0; i<strs[0].size(); i++){
            int j = 0;
            while(j<strs.size()-1){
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