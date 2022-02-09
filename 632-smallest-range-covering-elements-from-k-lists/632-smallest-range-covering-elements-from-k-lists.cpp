#define pii pair<int,int>
class Solution {
public:
  
  vector<int> smallestRange(vector<vector<int>>& nums) {
  int n = nums.size();
  vector<int> index(n, 0);  // for traversing the minimum element array
      
  priority_queue<pii, vector<pii>,greater<pii>> data; // MIN HEAP it will be paired with the index of array it is in.
      
  int max = INT_MIN;
  for (int i = 0; i < n; i++) {  
       if (nums[i][0] > max)
             max = nums[i][0];    // tracking local max to compare range
             data.push(make_pair(nums[i][0], i));
           }
  int range = max - data.top().first;
  vector<int>val = {data.top().first, max};
  while (true) {                
    int indo = data.top().second;
    int ind = ++index[indo];
    if (ind >=nums[indo].size())   // if it reaches end of array break
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