class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int ans = 0;
        for(auto x : piles){
            pq.push(x);
        }
        while(k--){
            int top = pq.top();
            pq.pop();
            top = top - top/2;
            pq.push(top);
        }
        while(!pq.empty()){
            int val = pq.top();
            ans+= val;
            pq.pop();
        }
        return ans;
    }
};