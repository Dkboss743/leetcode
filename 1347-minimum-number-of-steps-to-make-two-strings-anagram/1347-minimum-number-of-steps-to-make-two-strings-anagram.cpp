class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp;
        for(auto x  : s){
            mp[x]++;
            
        }
        for(auto x :  t){
            mp[x]--;
        }
        int cnt = 0;
        for(auto x : mp){
            if(x.second > 0){
                cnt+=x.second;
            }
            // if(x.second < 0){
            //     cnt-=x.second;
            // }
        }
        return cnt;
    }
};