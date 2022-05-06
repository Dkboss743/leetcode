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
      vector<int> hero;
      vector<pair<int,int>> ans;
      for(auto x : data)
          ans.push_back({x.first,x.second});
      sort(ans.begin(),ans.end(),Sort);
        for(auto x : ans)
        {
            int a = x.second;
            while(a--){
                hero.push_back(x.first);
            }
        }
        return hero;
    }
};