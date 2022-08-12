class Solution {
public:
    bool check(int cap, vector<int> &weights, int days){
        int temp  = 0;
        int n = weights.size();
        int ans = 1;
        for(int i=0; i<weights.size() ; i++){
            temp += weights[i];
            if(temp > cap){
                ans++;
                temp = weights[i];
                if(ans > days){
                    return false;
                }
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int start = *max_element(weights.begin(),weights.end());
        int val = 0;
        int end = accumulate(weights.begin(), weights.end() , 0);
        while(start <= end){
            int mid = start + (end - start)/2;
            if(check(mid,weights,days)){
                val = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return val;
    }
};