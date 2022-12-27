class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int aR) {
        vector<vector<int>> bag;
        int n = cap.size();
        for(int i=0; i<n ; i++){
            bag.push_back({cap[i] , rocks[i]});
        }
        sort(bag.begin() , bag.end() , [](vector<int> &a , vector<int> &b){
            return a[0]-a[1] < b[0]-b[1];
            
        });
        
        int ans = 0;
        for(auto x : bag){
            int rem = x[0] - x[1];
            if(aR - rem >=0){
                ans++;
                aR-=rem;
            }
        }
        return ans;
    }
};