class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        unordered_map<int,int> mp;
        for(int i = 0; i<n; i++){
            mp[tasks[i]]++;
        }
        priority_queue<int> pq;
        for(auto x : mp){
           pq.push(x.second); 
        }
        int ans = 0;
        while(!pq.empty()){
            int tasks = pq.top();
            pq.pop();
            if(tasks == 1){
                return -1;
            }
            if(tasks == 4){
                tasks -= 2;
            }
            else{
                tasks -= 3;
            }
            if(tasks > 0){
                pq.push(tasks);
            }
            ans++;
            
        }
        return ans;
    }
};