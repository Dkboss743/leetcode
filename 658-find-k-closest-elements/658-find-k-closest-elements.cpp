class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
 priority_queue<pair<int,int>> data;
  for (int i = 0; i < k; i++)
    data.push(make_pair(abs(arr[i] - x), arr[i]));
  for (int i = k; i < arr.size(); i++) {
    if (abs(arr[i] - x) < data.top().first ||
        (abs(arr[i] - x) == data.top().first &&
         (arr[i] < data.top().second))) {
      data.pop();
      data.push(make_pair(abs(arr[i] - x), arr[i]));
    }
  }
  vector<int> ans(k);
  for (int i = 0; i < k; i++) {
    ans[i] = data.top().second;
    data.pop();
  }
  sort(ans.begin(), ans.end());
  return ans;
    }
};