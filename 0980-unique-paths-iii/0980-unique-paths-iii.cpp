int dir_x[] = {0,1,0,-1};
int dir_y[] = {1,0,-1,0};
class Solution {
public:
    
    void util(vector<vector<int>> &grid , int &ans , int i , int j , set<string> st , int walls){
        int n = grid.size();
        int m = grid[0].size();
        string temp = to_string(i) + to_string(j);
        if(i>=n || i<0 || j<0 || j>=m){
            return;
        }
        if(grid[i][j] == -1){
            return;
        }
        if(st.find(temp)!=st.end()){
            return;
        }
        
        st.insert(temp);
        if(grid[i][j] == 2){
            if(st.size() == (n*m)-walls){
                ans++;
            }
            else{
                return;
            }
        }
        for(int k = 0; k<4; k++){
            util(grid, ans , i+dir_x[k] , j+dir_y[k] , st , walls);
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
       int ans = 0;
       set<string> st;
       int walls = 0;
       int x = 0;
       int y = 0;
       for(int i = 0; i<grid.size() ; i++){
           for(int j = 0; j<grid[0].size() ; j++){
               if(grid[i][j] == -1){
                   walls++;
               }
               if(grid[i][j] == 1){
                   x = i;
                   y = j;
               }
           }
       }
        util(grid , ans, x , y , st , walls);
        return ans;
    }
};