
class Solution {
public:
    
    int countPrimes(int n) {
        int ans = 0;
        vector<int> sieve(n+1,true);
        for(int i=2; i*i<n ; i++){
            if(sieve[i]){
            for(int j = i*i ; j<=n; j+=i){
                sieve[j] = false;
            }
            }
        }
        for(int i=2; i<n; i++){
            if(sieve[i]){
                ans++;
            }
        }
        return ans;
    }
};