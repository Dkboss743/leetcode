// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    bool isSafe(int x,int y,int val,int grid[N][N]){
        for (int j = 0; j < N; j++) {
    if (grid[x][j] == val || grid[j][y] == val)
      return false;
  }
  int s_x = (x / 3) * 3;
  int s_y = (y / 3) * 3;
  for (int i = s_x; i < s_x + 3; i++) {
    for (int j = s_y; j < s_y + 3; j++) {
      if (grid[i][j] == val)
        return false;
    }
  }
  return true; 
    }
    //Function to find a solved Sudoku. 
    bool SolveSudokuUtil(int i,int j, int n,int grid[N][N]){
        if(i == N){
           return true;
        }
        if(j == N){
            return SolveSudokuUtil(i+1,0,n,grid);
        }
        if(grid[i][j] != 0){
            return SolveSudokuUtil(i,j+1,n,grid);
        }
        for(int num = 1; num<=N; num++){
            if(isSafe(i,j,num,grid)){
                grid[i][j] = num;
                bool comp = SolveSudokuUtil(i,j+1,n,grid);
                if(comp){
                    return true;
                }
            }
        }
        grid[i][j] = 0;
        return false;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        SolveSudokuUtil(0,0,N,grid);
        // Your code here
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
      for (int i = 0; i < 9; i++) {
    {
      for (int j = 0; j < 9; j++) {
        cout << grid[i][j] << " ";
      }
    }
  } 
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends