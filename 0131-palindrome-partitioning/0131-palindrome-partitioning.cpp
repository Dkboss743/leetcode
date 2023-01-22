class Solution {
public:
    vector<vector<string>> ans;
    bool pal(string s){
        string t = s;
        reverse(s.begin() , s.end());
        return t==s;
    }
    void util(string &s , int i , vector<string> temp){
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
        vector<string> temp;
        util(s , 0  , temp);
        return ans;
    }
};