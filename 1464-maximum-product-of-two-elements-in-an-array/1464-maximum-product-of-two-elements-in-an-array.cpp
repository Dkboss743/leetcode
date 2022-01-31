class Solution {
public:
    int maxProduct(vector<int>& nums) {
      if(nums.size() == 2)
          return (nums[0]-1) * (nums[1] - 1);
      priority_queue<int,vector<int>,greater<int>> ans;
      ans.push(nums[0]);
      ans.push(nums[1]);
      for(int i=2; i<nums.size(); i++){
          if(nums[i]>ans.top())
          {
              ans.pop();
              ans.push(nums[i]);
          }
      }
      int val = 1;
      while(!ans.empty())
      {
          val *= (ans.top()-1);
          ans.pop();
      }
        return val;
      
    }
};