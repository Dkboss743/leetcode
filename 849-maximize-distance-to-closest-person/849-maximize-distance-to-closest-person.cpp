class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = -1;
        int val = 0;
        bool check_end = false;
        bool check_start = false;
        int n = seats.size();
        for(int i=0; i<n ; i++){
            val = 0;
            while(i<n && seats[i] == 0){
                if(i == 0)
                    check_start = true;
                val++;
                if(i==n-1)
                    check_end = true;
                i++;
            }
            if(val >=ans && check_end){
                return val;
            }
            else if(val >=ans && check_start){
                ans = val;
            }
            else{
            val = (val+1)/2;  
            ans = max(ans,val);
            }
            check_start = false;
        }
        return ans;
    }
};