class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> data;
        int n = nums.size();
      for(auto x : nums){
          data[x]++;
      }
      sort(nums.begin(),nums.end() ,[&](int a,int b){
          return data[a]!=data[b]?data[a]<data[b]:a>b; 
      });
        return nums;
    }
};