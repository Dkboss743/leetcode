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
int solveNQueensUtil(int n, int i, vector<string> &ans) {
  if (i == n) {
    return 1;
  }
  int cnt = 0;
  for (int j = 0; j < n; j++) {
    if (canPlaced(n, i, j, ans)) {
      ans[i][j] = 'Q';
      cnt += solveNQueensUtil(n, i + 1, ans);
      ans[i][j] = '.';
    }
  }
  return cnt;
}
 int totalNQueens(int n) {
  vector<string> board(n);
  string s(n, '.');
  for (int i = 0; i < n; i++)
    board[i] = s;

  int val = solveNQueensUtil(n, 0, board);

  return val;
}
};