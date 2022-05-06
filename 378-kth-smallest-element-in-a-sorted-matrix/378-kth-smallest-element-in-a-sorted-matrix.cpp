class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>data;
        int n = matrix.size();
        int temp = k;
        int row = 0;
        int col = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                data.push(matrix[i][j]);
                temp--;
                if(temp == 0){
                    row = i;
                    col = j;
                    break;
                }
            }
            if(temp == 0)
                break;
        }
        // cout << row << " " <<col << endl;
        if(col == n-1){
            col = -1;
            row++;
        }
        for(int i = row; i<n ; i++){
            for(int j = col+1; j<n ; j++){
                if(data.top()>matrix[i][j]){
                    // cout << matrix[i][j] << " ";
                    data.pop();
                    data.push(matrix[i][j]);
                }
                // cout << endl;
            }
            col = -1;
        }
        return data.top();
        
    }
};