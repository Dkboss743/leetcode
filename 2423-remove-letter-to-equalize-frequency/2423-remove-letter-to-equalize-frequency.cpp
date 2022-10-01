class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char,int> mp;
        for(auto x : word){
            mp[x]++;
        }
        vector<int> freq;
        for(auto x : mp){
            freq.push_back(x.second);
        }
        sort(freq.begin(),freq.end());
        if(freq.size() == 1){
            return true;
        }
        int val1 = freq[0];
        int val2 = freq[freq.size()-1];
        if(val1 == val2 && val1 == 1){
            return true;
        }
        int cnt1 = count(freq.begin() , freq.end() , val1);
        int cnt2 = count(freq.begin() , freq.end() , val2);
        if(cnt2 == 1 && val2 - val1 == 1){
            return true;
        }
        if(cnt1 == 1 && val2 - val1 == 1){
            return true;
        }
        return false;
    }
};