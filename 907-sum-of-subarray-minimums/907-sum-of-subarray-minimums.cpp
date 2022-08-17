class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       int n = arr.size();
       int MOD = 1e9 + 7;
       vector<int> left(n),right(n);
        stack<int> st;
        st.push(0);
        left[0] = 1;
        for(int i=1; i<n; i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                st.pop();
            }     
            if(st.empty()){
                left[i] = i+1;
            }
            else{
                left[i] = i - st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        st.push(n-1);
        right[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                right[i] = n-i;
            }
            else{
                right[i] = st.top() - i;
            }
            st.push(i);
        }
        int ans = 0;
        for(int i=0; i<n ;i++){
            long long temp = 0;
            temp = (left[i]*right[i])%MOD;
            temp = (temp*arr[i])%MOD;
            ans  = (ans + temp)%MOD;
        }
        return ans%MOD;
       
    }
};