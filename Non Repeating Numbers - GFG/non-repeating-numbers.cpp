// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int set_bit(int ans){
        int i=0;
        while(ans){
            if(ans&1)
            return (1<<i);
            ans>>=1;
            i++;
        }
    }
    vector<int> singleNumber(vector<int> nums) 
    {
        int ans=0;
        for(auto x : nums){
            ans = x^ans;
        }
        vector<int> val1;
        vector<int> val2;
        int val = set_bit(ans);
 
        for(auto x : nums){
            if(val&x){
                val1.push_back(x);
            }
            else
            {
                val2.push_back(x);
            }
        }
        int a = 0;
        for(auto x : val1){
            a = a^x;
        }
        int b=0;
        for(auto x : val2){
            b = b^x;
        }
        if(a>b)
        swap(a,b);
        return {a,b};
        
        
        // Code here.
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends