class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int val = 0;
        int n = gas.size();
        for(int i = 0; i<n; i++){
          
            val += gas[i]-cost[i];
        }
        if(val < 0){
            return -1;
        }
        val = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(val < 0){
                ans = i;
                val = 0;
            }
            val += gas[i] - cost[i];
        }
        return ans;
    }
};