class Solution {
public:
    bool wordPattern(string p, string s) {
        string a = "";
        int n = p.size();
        unordered_map<char, string > mp;
        int j = 0;
        for(int i = 0; i<n; i++){
            if(mp.find(p[i]) == mp.end()){
                mp[p[i]] = to_string(j++);
            }
            a+=mp[p[i]];
        }
        j = 0;
        string b = "";
        stringstream ss(s);
        string temp;
        unordered_map<string , string> mop;
        while(ss >> temp){
            if(mop.find(temp) == mop.end())
            {
                mop[temp] = to_string(j++);
            }
            b+=mop[temp];
        }
         // cout << a << " " << b << endl;
        return a == b;
    }
};