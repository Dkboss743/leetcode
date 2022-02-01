class Solution {
public:
    int nthUglyNumber(int n) {
    set<long int> ans;
    ans.insert(1);
    long int val = 1;
        while(n--){
            val = *(ans.begin());
            ans.erase(val);
            ans.insert(val * 2);
            ans.insert(val * 3);
            ans.insert(val * 5);
          
        }
    
        return val;
    }
};