#define ll long long int
class Solution {
public:
ll check(int n, int diffa, vector<int> &ans) {
  ll diff = 0;
  for (int i = sqrt(n); i >= 0; i--) {
    if (n % i == 0) {
      ll x = n / i;
      ll y = i;
      diff = abs(y - x);
      if (diff >= diffa)
        return diff;
      ans[0] = x;
      ans[1] = y;
      return diff;
    }
  }
return diff;
}
    vector<int> closestDivisors(int num) {
  vector<int> ans(2);
  int diff = check(num + 1, INT_MAX, ans);
  check(num + 2, diff, ans);
  return ans;
    }
};