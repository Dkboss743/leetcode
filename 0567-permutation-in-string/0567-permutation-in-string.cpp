class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26, 0) , mp2(26, 0);
        for(auto x : s1){
            mp1[x - 'a']++;
        }
    for(int i = 0; i<s2.size() ; i++){
        mp2[s2[i] - 'a']++;
        if(i >= s1.size()){
            mp2[s2[i-s1.size()] - 'a']--;
        }
        if(mp2 == mp1){
            return true;
        }
    }
    return false;

    }
};
