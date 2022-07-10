class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        vector<int> curr;
        prev = {1};
        for(int i=1; i<=rowIndex; i++){
            curr.resize(i+1);
            curr[0] = 1;
            curr[i] = 1;
            for(int j=1; j<i; j++){
               curr[j] = prev[j-1] + prev[j];
            }
            prev.resize(curr.size());
            prev=curr;
        }
        return prev;
    }
};