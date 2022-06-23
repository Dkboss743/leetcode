class Solution {
public:
  
    int first(string s,int k,unordered_map<char,int>data){
        for(int i=0; i<s.size() ; i++)
        {
            if(data[s[i]] < k){
                return i;
            }
        }
        return -1;
            
    }
    int lgs(string s,int k){
        unordered_map<char,int> data;
        for(auto x : s){
            data[x]++;
        }
        int val1 = -1;
        int val2 = -1;
        int f = first(s,k,data);
         // cout << f << endl;
        if(f == -1){
            return s.size();
        }
       
        if(f!=0){
         val1 = lgs(string(s.begin(),s.begin()+f),k);
        }
         val2 = lgs(string(s.begin()+f+1,s.end()),k);
        return max(val1,val2);
    }
    int longestSubstring(string s, int k) {  
        
        return lgs(s,k);
    }
};