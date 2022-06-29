class Solution {
public:
    int countOdds(int low, int high) {
        int nums = high-low;
        nums = nums/2;
        if(low%2 != 0 || high%2 != 0){
            nums++;
        }
        return nums;
    }
};