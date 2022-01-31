class Solution {
public:
    int squr(int a)
    {
        return a*a;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>>ans;
        for(auto x : points){
            ans.push({x[0]*x[0] + x[1]*x[1],x[0],x[1]});
        }
        while(ans.size()>k){
            ans.pop();
        }
        
        vector<vector<int>> data;
        while(!ans.empty()){
            auto x = ans.top();
            ans.pop();
            data.push_back({x[1],x[2]});
        }
        return data;
        
    }
};