class Solution {
public:
    int romanToInt(string s) {
    unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
    int ans = 0;
        int i = 0;
        for(i=0; i<s.size() ; i++){
            if(i<s.size()-1 && T[s[i]] < T[s[i+1]]){
                ans+=T[s[i+1]]-T[s[i]];
                i++;
            }
            else{
                ans+=T[s[i]];
            }
        }
        return ans;
     
    }
    
};