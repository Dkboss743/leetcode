// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    // bool canMove(int i, int j , int n,int m, vector<vector<int>> grid){
    //     return (i>=0 && j<m && j>=0 &&  i<n && (grid[i][j]!=0));
    // }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>cells;
        for(int i=0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 2){
                    cells.push({i,j});
                }
            }
        }
        int dir_x[4] = {0,1,0,-1};
        int dir_y[4] = {-1,0,1,0};
        int ans = 0;
        if(cells.empty())
        return -1;
        while(!cells.empty()){
            bool temp = false;
            int size = cells.size();
            for(int i = 0 ; i<size ; i++){
            int x = cells.front().first;
            int y = cells.front().second;
            cells.pop();
            for(int i = 0; i<4 ; i++){
                int mov_x = x + dir_x[i];
                int mov_y = y + dir_y[i];
                if(mov_x>=0 && mov_y<m && mov_y>=0 &&  mov_x<n && (grid[mov_x][mov_y]!=0)){
                    if(grid[mov_x][mov_y] == 1){
                        grid[mov_x][mov_y] = 2;
                        cells.push({mov_x,mov_y});
                        temp = true;
                    }
                }
            }
            }
            if(temp)
            ans++;
        }
        for(int i=0 ; i<n ; i++){
            for(int j= 0 ; j<m ; j++){
                if(grid[i][j] == 1)
                return -1;
            }
        }
        return ans;
        
    }
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends