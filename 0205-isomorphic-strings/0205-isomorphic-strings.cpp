class Solution {
public:
    bool isIsomorphic(string s, string t) {
         unordered_map<char, char> mp;
        unordered_set<char> str;

        for(int i = 0; i < s.length(); i++){
            char st = s[i];
            char tt = t[i];


            if(mp.count(st)){
                if(mp[st] != tt)
                return false;
            }
            else{
                if(str.count(tt))
                return false;
                mp[st] = tt;
                str.insert(tt);
            }
        }
        return true;
        
    }
};