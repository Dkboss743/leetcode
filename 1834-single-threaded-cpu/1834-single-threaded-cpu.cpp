
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int i = 0;
        for(auto &x : tasks){
            x.push_back(i++);
        }
        sort(tasks.begin() , tasks.end());
        int n = tasks.size();
        priority_queue<vector<int>,vector<vector<int>> ,greater<vector<int>>> pq;
       i = 0;
       long long int t = tasks[0][0];
        vector<int> ans;
        while(i<n || !pq.empty()){
            while(i < n && t>=tasks[i][0]){
                pq.push({tasks[i][1] , tasks[i][2]});
                i++;
            }
            if(pq.empty()){
                t = tasks[i][0];
            }
           else{
               auto it = pq.top();
               pq.pop();
               ans.push_back(it[1]);
               t+=it[0];
           }
        }
     return ans;
    }
};