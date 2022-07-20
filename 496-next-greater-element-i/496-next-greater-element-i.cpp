class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ans;
        stack<int> val;
        int n = nums2.size();
        for(int i = n-1 ; i>=0 ; i--){
            while(!val.empty() && val.top()<nums2[i]){
                val.pop();
            }
            if(val.empty()){
                ans[nums2[i]] = -1;
            }
            else{
                ans[nums2[i]] = val.top();
            }
            val.push(nums2[i]);
        }
        vector<int> temp;
        for(auto x : nums1){
            temp.push_back(ans[x]);
        }
        return temp;
        
    }
};