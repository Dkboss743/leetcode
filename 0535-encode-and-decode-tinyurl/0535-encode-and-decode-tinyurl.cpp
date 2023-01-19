class Solution {
public:

    // Encodes a URL to a shortened URL.
    string ans;
    unordered_map<string,string> mp;
    int len = 6;
    string hash(string l){
        string hashed = "";
        for(int i = 0; i<6; i++){
        int val = rand()%3;
        if(val == 0){
            hashed += to_string(rand()%10);
        }
        else if(val == 1){
            hashed += ('a' + rand()%26);
        }
        else{
            hashed += ('A' + rand()%26);
        }
        }
        if(mp.find(hashed)!=mp.end()){
            return hash(l);
        }
        mp[hashed] = l;
        return hashed;
    }
    string encode(string longUrl) {
         string t = "http://tinyurl.com/";
        cout << hash(longUrl) << endl;
        return t + hash(longUrl);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl.substr(shortUrl.size() - len, len)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));