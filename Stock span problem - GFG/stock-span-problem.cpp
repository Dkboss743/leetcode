// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        stack<pair<int,int>> stock;
        vector<int> ans;
        for(int i=0; i<n ; i++){
            int count = 1;
            while(!stock.empty() && stock.top().first <= price[i]){
                count += stock.top().second;
                stock.pop();
            }
            stock.push({price[i],count});
            ans.push_back(count);
        }
        return ans;
       // Your code here
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends