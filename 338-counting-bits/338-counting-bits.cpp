class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
        string temp = bitset<64>(i).to_string();
        ans.push_back(count(temp.begin(),temp.end(),'1'));
        }
        return ans;
    }
};