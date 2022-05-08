// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    // bool visited[10000] = false;
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        bool visited[V] = {false};
        queue<int> ans;
        vector<int> val;
        ans.push(0);
        while(!ans.empty()){
            int size = ans.size();
            for(int i = 0 ; i<size ; i++){
                int index = ans.front();
                ans.pop();
                for(int j = 0 ; j<adj[index].size() ; j++){
                    if((visited[adj[index][j]]) == false){
                    ans.push(adj[index][j]);
                    visited[adj[index][j]] = true;
                    }
                }
                 val.push_back(index);
            }
        }
        return val;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends