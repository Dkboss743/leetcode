class Solution {
public:
    int find(int val , vector<int> &nums){
        int st = 0;
        int ans = -1;
        int en = nums.size()-1;
        while(st<=en){
            int mid = st+(en-st)/2;
            // cout << st << " " <<nums[mid] << " " << en << " || " << ans << endl;
            if(nums[mid] > val){
                en = mid-1;
            }
            else {
                ans = mid;
                st = mid+1;
            }
        }
        if(ans == -1){
            return 0;
        }
        // cout << "##################" << endl;
        return ans+1;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin() , nums.end());
        for(int i=1; i<nums.size() ; i++){
            nums[i] += nums[i-1];
        }
        // for(auto x : nums){
        //     cout << x << " ";
        // }
        // cout << endl;
        vector<int> ans;
        for(int i=0; i<queries.size() ; i++){
            int val = queries[i];
            ans.push_back(find(val, nums));
        }
        return ans;
    }
};