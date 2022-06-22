class Solution {
public:
    string countAndSay(int n) {
        
        string a = "11";
        if(n == 1){
            return "1";
        }
        if(n == 2){
            return "11";
        }
        n-=2;
        while(n--){
            int cnt = 1;
            string temp = "";
            int m  = a.size();
            for(int i=0 ; i<m; i++){
                while(i<m-1 && a[i] == a[i+1]){
                    cnt++;
                    i++;
                }
                // cout << i << endl;
               temp+=to_string(cnt)+a[i];
              cnt = 1;
            }
            a = temp;
        }
        return a;
        
    }
};