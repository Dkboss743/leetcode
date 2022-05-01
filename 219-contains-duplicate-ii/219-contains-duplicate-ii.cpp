
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>data;
        data[nums[0]] = 1;
       for(int i=1; i<n ; i++){
           if(data[nums[i]]&&(i-data[nums[i]] < k)){
            return true;
           }
           data[nums[i]]=i+1;
       }
        return false;
    }
};