// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isUtil(int n,int m,vector<vector<int>> edges){
       
        vector<int>dis(n,INT_MAX);
        dis[0] = 0;
        for(int j=0; j<n-1; j++){
        for(int i=0; i<m; i++){
            int from = edges[i][0];
            int to = edges[i][1];
            int wt = edges[i][2];
            if(dis[from]!=INT_MAX && dis[from] + wt < dis[to]){
                dis[to] = dis[from] + wt;
            }
        }
        }
        for(int i=0; i<m; i++){
            int from = edges[i][0];
            int to = edges[i][1];
            int wt = edges[i][2];
            if(dis[from]!=INT_MAX && dis[from] + wt < dis[to]){
                return true;
            }
        }
        return false;
    }
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	   return isUtil(n,edges.size(),edges)?1:0;
	    
	   
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends