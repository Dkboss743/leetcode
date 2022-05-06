class Solution {
public:
    bool static Sort(pair<int,int> &a, pair<int,int> &b){
         if(a.second == b.second){
            return (a.first > b.first);
          }
          else
              return a.second < b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> data;
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