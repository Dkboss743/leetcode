class Solution {
public:
    string solve(string s){
        stack<char> a;
        string ans = "";
        for(int i=0; i<s.size() ; i++){
            if(!a.empty() && s[i] == '#'){
                a.pop();
            }
            else{
                if(s[i]!='#')
                a.push(s[i]);
            }
        }
        while(!a.empty()){
            ans += a.top();
            a.pop();
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        // cout << solve(s) <<" " << solve(t) << endl;
        return solve(s) == solve(t);
    }
};