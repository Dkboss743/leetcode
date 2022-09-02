class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto x : t){
            mp[x]++;
        }
        string str = "";
        int start = 0;
        int move = 0;
        int n = s.size();
        int m = t.size();
        int temp = 0;
        int ans = INT_MAX;
        while(move < n)
        {
            if(mp[s[move]] > 0){
                m--;
            }
            mp[s[move]]--;
            move++;
            while(m==0){
                if(ans > move-start){
                    ans = move-start;
                    temp = start;
                }
                mp[s[start]]++;
                if(mp[s[start]] > 0){
                m++;
                }
                start++;
            }
            
        }
        return ans == INT_MAX ? "" : s.substr(temp,ans);
    }
};