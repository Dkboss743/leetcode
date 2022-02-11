class Solution {
public:   
    int matrixScore(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        int ans = (1<<(width-1))*height;  /* [1000]
                                             [1000]
                                             [1000]   */  
/*if [row,col] == [row,0] which means they will be 1 so we can swap if they are less than non equal ones*/
        for(int col=1 ; col<width; col++){
            int flips = 0;
             for(int row=0; row<height; row++){
                 if(grid[row][col] == grid[row][0])
                     flips++;
             }  
            ans+=max(flips,height-flips)*(1<<(width-1-col));
        }
        return ans;
        
    }
};