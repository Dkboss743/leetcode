// custom hash function
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
          return hash1;
    }
};
class Solution {
public:
    // finding slope of every point with every other point and then taking maximum points having same slope
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for(int i = 0; i<n ; i++){  
            // here is used pair<int,int> as double can be unpredictable cause we want to make sure that key matches
            //exactly so we can use pair as <numerator , denominator> for that
            unordered_map<pair<int, int>, int, hash_pair> mp;
            for(int j=0; j<n; j++){
                if(i == j){
                    continue;
                }
                // saving slope as {num , denom}
                int num = points[i][0] - points[j][0];
                int denom = points[i][1] - points[j][1];
                int gcd = __gcd(num ,denom); // to convert into their base form {2, 4} -> {1, 2}
                num /= gcd;
                denom /= gcd;
                mp[{num,denom}]++; 
            }
            for(auto x : mp){
                ans = max(ans , 1+x.second);
            }
        }
        return ans;
       
    }
};