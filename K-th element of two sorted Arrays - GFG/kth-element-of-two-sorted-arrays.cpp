// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        multiset<int> s;
        for(int i=0 ; i<n ; i++){
            s.insert(arr1[i]);
        }
        for(int j=0 ; j<m ; j++){
            s.insert(arr2[j]);
        }
        auto itr = s.begin();
        // for(auto a : s){
        //     cout << a << " ";
        // }
        // cout << endl;
        for(int i=0 ; i<k-1 ; i++){
            itr++;
        }
        return *itr;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends