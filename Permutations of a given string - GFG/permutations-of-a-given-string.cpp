// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void perm(string S, int i , vector<string>&ans){
	        int n = S.size();
	        if(i == n){
	            ans.push_back(S);
	        }
	        for(int j=i; j<n; j++){
	            swap(S[j],S[i]);
	            perm(S,i+1,ans);
	            swap(S[j],S[i]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    perm(S,0,ans);
		    sort(ans.begin(),ans.end());
		    auto itr = unique(ans.begin() , ans.end());
		    ans.resize(distance(ans.begin(),itr));
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends