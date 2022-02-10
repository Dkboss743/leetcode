class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while(x>0 || y>0){
        int last_bit1 = x&1;
        int last_bit2 = y&1;
        x>>=1;
        y>>=1;
        if(last_bit1 ^ last_bit2)
            count++;
        }
        return count;
        
    }
};