class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> freq;
        int n = s.size();
        int odd = n%2;
        int max_freq = n%2?(n/2)+1:n/2;
      
        for(auto x : s){
            freq[x]++;
            if(freq[x] > max_freq){
                return "";
            }
        }
        vector<pair<int,char>> sortedString;
        for(auto x : freq){
            int val1 = x.first;
            int val2 = x.second;
            sortedString.push_back({val2,val1});
        }
        sort(sortedString.begin(),sortedString.end(),greater<pair<int,char>>());
        string ans;
        ans.resize(n,'0');
        int i=0;
        int k = 1;
        for(auto x: sortedString){
            char ins = x.second;

            int times = x.first;
           
            while(i<n && times--){
                while(i<n && ans[i] != '0'){
                    i++;
                }
                ans[i]=ins;
                if(times == 0){
                    break;
                }
                i+=2;
            }
            // cout << ans << " " << i << endl;
            if(times>0){
                i = 1;
                k = 2;
                while(i<n && times--){
                while(i<n && ans[i] != '0'){
                    i++;
                }
                   ans[i] = ins;
                    if(times==0){
                        break;
                    }
                    i+=2;
                }
            }
            i+=k;
        }
        return ans;
        
    }
};