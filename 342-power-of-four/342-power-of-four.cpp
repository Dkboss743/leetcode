class Solution {
public:
    bool isPowerOfFour(int n) {
     long long int count = 0;
     if(n<0)
         return false;
     if(n && !(n&(n-1))){
         while(n>1)
         {
             n >>=1;
             count++;
         }
         return !(count&1);
     }
     return false;
    }
};