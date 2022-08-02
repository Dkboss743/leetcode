class Solution {
public:
    int di[4] = {0,1,-1,0};
    int dj[4] = {1,0,0,-1};
    bool isValid(int x , int y, int n , int m){
        
        if(x >= n || x< 0 || y < 0 || y>=m){
           return false;
       }
        return true;
    }
    int util(vector<vector<int>> &grid, vector<vector<int>> &visited , int x , int y){
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 1;
        visited[x][y] = 1;
        for(int i=0; i<4; i++){
            int ind_x = x+di[i];
            int ind_y = y+dj[i];
            if(isValid(ind_x,ind_y,n , m)){
                if(grid[ind_x][ind_y]==1 && visited[ind_x][ind_y]==-1){
                    cnt += util(grid, visited , ind_x , ind_y);
                }
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m=  grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,-1));
        int ans = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]==-1 && grid[i][j] == 1){
                    ans = max(ans , util(grid,visited,i,j));
                }
            }
        }
        return ans;
        
    }
};