class Solution {
public:
    vector<int> par;
    vector<int> rank;
    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }
    void Union(int x, int y){
        int p1 = find(x);
        int p2 = find(y);
        if(p1 != p2){
            if(rank[p2] >=rank[p1]){
                par[p1] = p2;
                if(rank[p2] == rank[p1]){
                    rank[p2]++;
                }
            }
            else{
                par[p2] = p1;
            }
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        int ans = vals.size();
        par = vector<int> (n,0);
        rank = vector<int> (n,0);
        for(int i = 0; i<n; i++){
            par[i] = i;
        }
        map<int,vector<int>>mp;
        for(int i = 0; i<vals.size() ; i++){
            mp[vals[i]].push_back(i);
        }
        vector<vector<int>> gr(n);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            if(vals[u] >= vals[v]){
                gr[u].push_back(v);
            }
            else{
                gr[v].push_back(u);
            }
        }
        for(auto node  : mp){
            int temp = 0;
            vector<int> nodes = node.second;
            for(int i=0; i<nodes.size() ; i++){
                for(int j = 0; j<gr[nodes[i]].size() ; j++){
                    Union(nodes[i] , gr[nodes[i]][j]);
                }
            }
            unordered_map<int,int> count;
            for(int i = 0; i<nodes.size() ; i++){
                count[find(nodes[i])]++;
            }
            for(auto x : count){
                ans += ((x.second)*(x.second-1))/2;
            }
            
        }
        return ans;
    }
};