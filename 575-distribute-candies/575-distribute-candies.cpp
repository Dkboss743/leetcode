class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> ans;
        for(auto x : candyType)
            ans.insert(x);
        int n = candyType.size();
        if(ans.size() <=n/2)
            return ans.size();
        else
            return n/2;
    }
};