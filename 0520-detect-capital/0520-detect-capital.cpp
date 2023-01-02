class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0;
        int n = word.size();
        bool con = (word[0] >='A' && word[0]<='Z');
        for(int i = 0 ; i<n; i++){
            if(word[i] >= 'A' && word[i] <='Z'){
                cap++;
            }
        }
    
        return (cap == n) || (cap == 0) || (con && (cap == 1));
    }
};