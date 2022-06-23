class Solution {
public:
    vector<vector<string>> ans;
    bool static isPalindrome(string a){
        string rev = a;
        reverse(a.begin(),a.end());
        return rev == a;
    }
    
    void subs(string temp,int index,string s,vector<string> &run_str){
        int n = s.size();
        if(index == n){
            ans.push_back(run_str);
            return;
        }
        for(int i=index; i<n; i++){
            temp +=s[i];
            if(isPalindrome(temp)){
                run_str.push_back(temp);
                subs("",i+1,s,run_str);
                run_str.erase(run_str.end());
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string>run_str;
        subs("",0,s,run_str);
        return ans;
    }
};