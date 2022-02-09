class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
  vector<int> index(n, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>> data;
  int max = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (nums[i][0] > max)
      max = nums[i][0];
    data.push(make_pair(nums[i][0], i));
  }
  int range = max - data.top().first;
  vector<int>val = {data.top().first, max};
  while (1) {
    int indo = data.top().second;
    int ind = ++index[indo];
    if (ind >=nums[indo].size())
      break;
    if (nums[indo][ind] > max )
      max =nums[indo][ind];
    data.pop();
    data.push(make_pair(nums[indo][ind], indo));
    int min = data.top().first;
    if (max - min < range) {
      val[0] = min;
      val[1] = max;
      range = max - min;
    }
  }
        return val;
    
    }
};