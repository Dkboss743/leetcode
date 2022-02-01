class Solution {
public:
    int minSetSize(vector<int>& arr) {
      map<int,int> data;
      for(auto x : arr){
          data[x]++;
      }
      multimap<int,int,greater<int>> ans;
      for(auto x : data){
          ans.insert(make_pair(x.second,x.first));
      }
      int size = 0;
      int val = 0;
      for(auto x : ans){
          size+=x.first;
          val++;
          if(size>=arr.size()/2){
              break;
          }
      }
        return val;
    }
};