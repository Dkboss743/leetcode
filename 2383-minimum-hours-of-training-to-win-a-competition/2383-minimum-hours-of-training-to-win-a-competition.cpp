class Solution {
public:
    int minNumberOfHours(int i, int e, vector<int>& ener, vector<int>& exp) {
        int cnt=0, diff;
         int ans = accumulate(ener.begin(),ener.end(),0) + 1 - i;
        if(ans < 0){
            ans = 0;
        }
         for(auto x : exp){
            if(e <= x){
                cnt+= x-e+1;
                e = x+1;   
            }
                e+=x;
            }
        return cnt+ans;
    }
};

