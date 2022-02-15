class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int,int> ans;
        for(auto x : candyType)
            ans[x]++;
        int n = candyType.size();
        if(ans.size() <=n/2)
            return ans.size();
        else
            return n/2;
    }
};