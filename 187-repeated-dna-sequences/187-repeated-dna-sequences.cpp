class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int>ans;
        vector<string>val;
        int n = s.size();
        for(int i=0 ; i<=n-10 ; i++){
           string temp =  s.substr(i,10);
            ans[temp]++;
           if(ans[temp]==2){
               val.push_back(temp);
           }
        }
        return val;
    }
};