class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = -1;
        int val = 0;
        bool temp = true;
        int n = seats.size();
        for(int i=0; i<n ; i++){
            val = 0;
            while(i<n && seats[i] == 0){
                val++;
                i++;
            }
            if(temp && seats[0] == 0){
                ans = val;
                temp = false;
            }
            if(i == n && seats[n-1] == 0 && val>=ans){
                ans = val;
            }
            else{
            val = (val+1)/2;  
            ans = max(ans,val);
            }
        }
        return ans;
    }
};