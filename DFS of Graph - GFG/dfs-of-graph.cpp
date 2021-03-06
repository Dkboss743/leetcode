// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    bool visited[10000] = {false};
    void dfs(int V,vector<int> adj[],vector<int> &ans){
        visited[V]  = true;
        ans.push_back(V);
        for(int j = 0 ; j<adj[V].size() ; j++){
            if(visited[adj[V][j]] == false){
                dfs(adj[V][j],adj,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<int> ans;
       dfs(0,adj,ans);
       return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends