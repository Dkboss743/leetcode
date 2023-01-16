class Solution {
public:
   
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n == 0){
            ans.push_back(newInterval);
            return ans;
        }
        for(int i = 0; i<n; i++){
            if(intervals[i][1] < newInterval[0]){
                ans.push_back(intervals[i]);
            }
            else{
                int j = i;
                newInterval[0] = min(newInterval[0] , intervals[i][0]);
                int val = 0;
                for(j ; j<n; j++){
                    if(newInterval[1] >=intervals[j][0] && newInterval[1] <= intervals[j][1]){
                        newInterval[1] = intervals[j][1];
                        break;
                    }
                    else if(intervals[j][0] > newInterval[1]){
                        val = -1;
                        break;
                    }
                }
                i = j + val;
                ans.push_back({newInterval[0] , newInterval[1]});
                newInterval[0] = INT_MAX;
            }
        }
        if(newInterval[0] != INT_MAX){
            ans.push_back(newInterval);
        }
        return ans;
            
    }
};