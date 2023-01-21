class Solution {
public:
    vector<string> ans;
    void util(string s , int i, string cur, int dot){
        int n = s.size();
        string temp = "";
        for(int j=i; j<n; j++){
            if(dot == 3){
                int temp = stoll(s.substr(j));
                if(temp <= 255 && temp >= 0 && (s[j] !='0' || j == n-1)){
                    ans.push_back(cur + s.substr(j));
                }
                return;
            }
            int sz = 0;
            temp += s[j];
            int val = stoi(temp);
            if(val>255 || val < 0 || (temp[0] == '0' && temp.size() > 1)){
                break;
            }
            cur += temp + ".";
            util(s , j+1 , cur  , dot + 1);
            cur.erase(cur.size() - temp.size() - 1, temp.size()  + 1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        util(s , 0 , "" , 0);
        return ans;
    }
};