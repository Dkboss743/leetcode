class Solution {
public:
    vector<int> par;
    int find(int x){
        if(par[x] == -1){
            return x;
        }
        return par[x] = find(par[x]);
    }
    void Union(int x , int y){
        x = find(x);
        y = find(y);
        if(x != y){
            par[max(x,y)] = min(x,y);
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
          int n = s1.size();
          par = vector<int> (26 , -1);
          for(int i = 0; i<s1.size() ; i++){
              Union(s1[i]-'a' , s2[i]-'a');
          }
        string ans = "";
        for(auto x : baseStr){
            ans += 'a' + find(x-'a');
        }
        return ans;
          
    }
};