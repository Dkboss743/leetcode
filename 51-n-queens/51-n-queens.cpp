class Solution {
public:
   bool canPlaced(int n, int i, int j, vector<string> &ans) {
  int x = i;
  int y = j;
  for (int k = 0; k < x; k++) {
    if (ans[k][y] == 'Q')
      return false;
  }
  while (x >= 0 && y >= 0) {
    if (ans[x][y] == 'Q')
      return false;
    x--;
    y--;
  }
  x = i;
  y = j;
  while (x >= 0 && y <= n) {
    if (ans[x][y] == 'Q')
      return false;
    x--;
    y++;
  }
  return true;
}
bool solveNQueensUtil(int n, int i, vector<string> &ans,
                      vector<vector<string>> &sol) {
  if (i == n) {
    sol.push_back(ans);
    return true;
  }
  for (int j = 0; j < n; j++) {
    if (canPlaced(n, i, j, ans)) {
      ans[i][j] = 'Q';
      solveNQueensUtil(n, i + 1, ans, sol);
      ans[i][j] = '.';
    }
  }
  return false;
}
vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> ans;
  vector<string> board(n);
  string s(n, '.');
  for (int i = 0; i < n; i++)
    board[i] = s;
  for (auto x : board) {
    cout << x << endl;
  }

  solveNQueensUtil(n, 0, board, ans);

  return ans;
}
};