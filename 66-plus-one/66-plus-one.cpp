class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for(int i=n-1; i>=0; i--){
            int val = digits[i]+carry;
            carry = val/10;
            val = val%10;
            digits[i] = val;
            if(carry == 0){
                return digits;
            }
        }
        if(carry){
                    vector<int> ans(n+1);
            ans[0] = carry;
            int i=1;
            for(auto x : digits)
                ans[i++] = x;
            return ans;
        }
        return digits;
    }
};