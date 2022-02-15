class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> ans;
        for(auto x : candyType)
            ans[x]++;
        int n = candyType.size();
        if(ans.size() <=n/2)
            return ans.size();
        else
            return n/2;
    }
};