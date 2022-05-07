// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		   queue<char> ans;
		   unordered_map<char,int> data;
		   string val = "";
		   for(int i= 0 ; i<A.size() ; i++){
		       data[A[i]]++;
		       if(data[A[i]] == 1){
		           ans.push(A[i]);
		       }
		       while(!ans.empty() && data[ans.front()]>1){
		           ans.pop();
		       }
		       if(ans.empty()){
		           val+='#';
		       }
		       else
		       val+=ans.front();
		   }
		   return val;
		   
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends