class Solution {
public:
    vector<vector<string>> ans;
    bool pal(string s){
         for(int i=0;i<s.size()/2;++i){
            if(s[i]==s[s.size()-1-i]){
                continue;
            }
            return false;
        }
        return true;
    }
    void util(string &s , int i , vector<string> temp = {}){
        int n = s.size();
        if(i == n){
            ans.push_back(temp);
        }
        string val = "";
        for(int k = i; k<n; k++){
           val += s[k];
            if(pal(val)){
                temp.push_back(val);
                util(s , k+1 , temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       
        util(s , 0);
        return ans;
    }
};