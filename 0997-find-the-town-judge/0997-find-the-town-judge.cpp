class Solution {
public:
    
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> gr(n+1 , 0);
        for(int i = 0; i<trust.size() ; i++){
            gr[trust[i][1]]++;
            gr[trust[i][0]]--;
        }
        for(int i = 1; i<=n; i++){
            if(gr[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};