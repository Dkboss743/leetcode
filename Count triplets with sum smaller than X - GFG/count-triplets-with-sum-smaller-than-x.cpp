// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	     sort(arr,arr+n);
	     long long int cnt = 0;
	     for(int i=0; i<n; i++){
	         int j = n-1;
	         int m= i+1;
	         while(m<j){
	             int val = arr[i] + arr[m] + arr[j];
	             if(val < sum){
	                 cnt += (j-m);
	                 m++;
	             }
	             else{
	                 j--;
	             }
	         }
	     }
	     return cnt;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends