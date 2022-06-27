// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        int count_dist = 0;
        set<char> data;
        for(auto x : str){
            data.insert(x);
        }
        count_dist = data.size();
        map<char,int> sml;
        int len = INT_MAX;
        int j=0;
        for(int i=0; i<str.size() ;i++ ){
            sml[str[i]]++;
            while(j<=i && sml.size() == count_dist){
                len = min(len,i-j+1);
                sml[str[j]]--;
                if(sml[str[j]] == 0){
                    sml.erase(str[j]);
                }
                j++;
            }
        }
        return len;
    
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends