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
                int i = st;
                while(i<en && s[i] != s[en]){
                    i++;
                }
                if(i ==en){
                    swap(s[en] , s[en-1]);
                    ans++;
                }
                else{
                    while(i>st){
                        swap(s[i] , s[i-1]);
                        i--;
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