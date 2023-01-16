class Solution {
public:
   
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n == 0){
            ans.push_back(newInterval);
            return ans;
        }
        int i = 0;
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i++]);
        }
        if(i == n){
            ans.push_back(newInterval);
            return ans;
        }
        newInterval[0] = min(newInterval[0] , intervals[i][0]);
        for(i ; i<n; i++){
            if(newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]){
                newInterval[1]  = intervals[i][1];
                i++;
                break;
            }
            else if(intervals[i][0] > newInterval[1]){
                break;
                
            }
            
        }
        ans.push_back(newInterval);
        while(i < n){
            ans.push_back(intervals[i++]);
        }
        return ans;
            
    }
};