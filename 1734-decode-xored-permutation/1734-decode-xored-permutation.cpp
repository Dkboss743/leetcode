class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();
        int x_or = 0;
         int x_or_last = encoded[0];
        for(int i=1; i<=n+1; i++){
            x_or = x_or ^ i;
            if(!(i&1) && i<n)
                x_or_last ^=encoded[i];
        }
        int last_element = x_or_last ^ x_or;
        vector<int> arr(n+1);
        arr[n] = last_element;
        for(int i=n-1 ; i>=0; i--){
            arr[i] = arr[i+1]^encoded[i];
        }
        return arr;
    }
};