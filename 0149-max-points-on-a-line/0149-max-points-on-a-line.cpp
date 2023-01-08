struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
class Solution {
public:
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for(int i = 0; i<n ; i++){  
            unordered_map<pair<int, int>, int, hash_pair> mp;
            int x = points[i][0];
            int y = points[i][1];
            for(int j=0; j<n; j++){
                if(i == j){
                    continue;
                }
                int new_x = x - points[j][0];
                int new_y = y - points[j][1];
                if(new_x < 0 && new_y < 0){
                    new_x = -new_x;
                    new_y = -new_y;
                }
                else if(new_y < 0){
                    new_x = -new_x;
                    new_y = -new_y;
                }
                int denom = __gcd(abs(new_x) , abs(new_y));
                new_x /= denom;
                new_y /= denom;
                pair<int,int> temp(new_x , new_y);
                mp[temp]++; 
            }
            for(auto x : mp){
                ans = max(ans , 1+x.second);
            }
        }
        return ans;
       
    }
};