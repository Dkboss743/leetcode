class Solution {
public:
       void util(vector<vector<int>> &graph , int ind , vector<vector<int>> &ans , vector<int> temp){
        int n = graph.size();
        if(ind == n-1){
            ans.push_back(temp);
            return; 
        }
        for(auto to : graph[ind]){
            temp.push_back(to);
            util(graph , to , ans , temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        util(graph, 0 , ans , temp);
        return ans;
    }
};