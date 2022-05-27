// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<int> dir_x = {1,0,0,-1};
    vector<int> dir_y = {0,-1,1,0};
    string dir_c = "DLRU";
    vector<string>ans;
    
    // bool visited [100][100] = {false};
    bool isValid(int x , int y , int n,vector<vector<int>>&m, vector<vector<bool>> &visited){
        return (x>=0 && x<n && y<n && y>=0 && m[x][y] == 1 && visited[x][y] == false);
    }
    void dfs(string path,vector<vector<int>> &m,int n,int x,int y, vector<vector<bool>> &visited){
        if(x == n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y] = true;
        for(int i=0 ; i<4 ; i++){
            if(isValid(x+dir_x[i],y+dir_y[i],n,m,visited)){
                    dfs(path+dir_c[i] , m , n , x+dir_x[i] , y+dir_y[i],visited);
            }
        }
        visited[x][y] = false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] == 0 || m[n-1][n-1] == 0)
        return ans;
       vector<vector<bool>> visited(6,vector<bool>(6,false));
       dfs("",m,n,0,0,visited);
       return ans;
    }
};
    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends