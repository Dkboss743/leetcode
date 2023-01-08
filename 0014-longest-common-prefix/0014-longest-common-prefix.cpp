class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int j = 0;
        if(strs.size() == 1){
            return strs[0];
        }
        string ans = "";
        int n = strs.size();
        while(true){
        for(int i = 0; i<n-1; i++){
            if(j >= strs[i].size()){
                return ans;
            }
            if(strs[i][j] != strs[i+1][j]){
                return ans;
            }
        }
            ans+= strs[0][j];
            j++;
        }
        return ans;
    }
};