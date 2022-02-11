class Solution {
public:   
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = (1<<(m-1))*n;
        for(int col=1 ; col<m; col++){
            int flips = 0;
             for(int row=0; row<n; row++){
                 if(grid[row][col] == grid[row][0])
                     flips++;
             }  
            ans+=max(flips,n-flips)*(1<<(m-1-col));
        }
        return ans;
        
    }
};