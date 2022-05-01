
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>data;
       for(int i=0; i<n ; i++){
           if(!data.empty()){
               if(data.find(nums[i])!=data.end()){
                   if(i-data[nums[i]] <=k)
                       return true;
               }
           }
           data[nums[i]]=i;
       }
        return false;
    }
};