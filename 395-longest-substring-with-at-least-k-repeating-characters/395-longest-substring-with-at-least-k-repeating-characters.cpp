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
        if(s.size() == 0){
            return 0;
        }
        unordered_map<char,int> data;
        for(auto x : s){
            data[x]++;
        }

        int f = first(s,k,data);
        if(f == -1){
            return s.size();
        }
         int val1 = lgs(string(s.begin(),s.begin()+f),k);
         int val2 = lgs(string(s.begin()+f+1,s.end()),k);
        return max(val1,val2);
    }
    int longestSubstring(string s, int k) {  
        
        return lgs(s,k);
    }
};