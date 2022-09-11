class Solution {
public:
    static bool comp(vector<int> &a , vector<int> &b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin() , in.end() , comp);
        vector<vector<int>> ans;
        int n = in.size();
        ans.push_back(in[0]);
        int k = 0;
        for(int i=1; i<n ;i++){
            if(in[i][0] <= ans[k][1]){
                ans[k][0] = min(ans[k][0] , in[i][0]);
                ans[k][1] = max(ans[k][1] , in[i][1]);
            }
            else{
                ans.push_back(in[i]);
                k++;
            }
        }
        return ans;
    }
};