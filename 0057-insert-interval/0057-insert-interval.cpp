class Solution {
public:
   
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int st = newInterval[0];
        int en = newInterval[1];
        if(n == 0){
            ans.push_back(newInterval);
            return ans;
        }
        for(int i = 0; i<n; i++){
            if(intervals[i][1] < st){
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0]>st && intervals[i][0] >=en){
                
                if(intervals[i][0] == en){
                    ans.push_back({st  , intervals[i][1]});
                }
                else{
                    ans.push_back({st , en});
                    ans.push_back(intervals[i]);
                    
                }
                st = INT_MAX;
            }
            else{
                int j = i;
                int s = min(st , intervals[i][0]);
                int val = 0;
                for(j ; j<n; j++){
                    if(en >=intervals[j][0] && en <= intervals[j][1]){
                        en = intervals[j][1];
                        break;
                    }
                    else if(intervals[j][0] > en){
                        val = -1;
                        break;
                    }
                }
                i = j + val;
                ans.push_back({s , en});
                st = INT_MAX;
            }
        }
        if(st != INT_MAX){
            ans.push_back(newInterval);
        }
        return ans;
            
    }
};