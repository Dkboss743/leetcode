class Solution {
public:
    void dfs(vector<vector<int>> &gr , int node , unordered_map<int, int> &mp , int dis , vector<bool> &vis){
        mp[node] = dis;
        vis[node] = true;
        if(gr[node].size() == 0 || vis[gr[node][0]]){
            return;
        }
        dfs(gr , gr[node][0] , mp , dis+1 , vis);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1 == node2){
            return node1;
        }
        int n = edges.size();
        vector<vector<int>> gr(n);
        for(int i = 0; i<n ; i++){
            if(edges[i] != -1){
              gr[i].push_back(edges[i]);
            }
        }
        int k = 0;
       
        vector<bool> vis(n , false);
        unordered_map<int,int> n1;
         dfs(gr , node1 , n1 , 0 , vis);
        vis = vector<bool>(n , false);
        unordered_map<int,int> n2;
         dfs(gr , node2 , n2 , 0 , vis);
        int ans = INT_MAX;
        int dis = INT_MAX;
        
        for(auto x : n1){
            if(n2.find(x.first) != n2.end()){
                int val = max(n2[x.first] , x.second);
                if(val < dis){
                    ans = x.first;
                    dis = val;
                }
                else if(val == dis){
                    if(x.first < ans){
                        ans = x.first;
                    }
                }
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
        
    }
};