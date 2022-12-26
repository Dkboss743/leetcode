class Solution {
public:
   
    int minMovesToMakePalindrome(string s) {
       int n = s.size();
        int st = 0;
        int en = n-1;
        int ans = 0;
        while(st < en){
            if(s[st] == s[en]){
                st++;
                en--;
            }
            else{
                int i = en;
                while(i>st && s[i] != s[st]){
                    i--;
                }
                if(i == st){
                    swap(s[st] , s[st+1]);
                    ans++;
                }
                else{
                    while(i<en){
                        swap(s[i] , s[i+1]);
                        i++;
                        ans++;
                    }
                    st++;
                    en--;
                }
            }
        }
        return ans;
        
    }
};