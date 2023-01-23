class Solution {
public:
    
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> gr(n+1 , 0);
        for(auto x : trust){
            int a = x[0];
            int b = x[1];
            gr[b]++;
            gr[a]--;
        }
        int ans = -1;
        for(int i = 1; i<=n; i++){
            if(gr[i] == n-1){
                ans = i;
                break;
            }
        }
        return ans;
    }
};