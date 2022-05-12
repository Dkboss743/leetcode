// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
       sort(arr,arr+n);
       long long int temp = 1;
       long long int sum = 0;
       long long int ans = 0;
       int i = n-1;
       for(i = n-1;i>0; i-=2){
        //   cout << i << endl;
           sum += arr[i]+arr[i-1];
        //   cout << sum << endl;
           ans += (sum%10)*temp;
           sum = sum/10;
           temp*=10;
       }
       if(i==0){
        //   cout << sum << "  " << temp << endl;
           ans += temp*(sum+arr[0]);
           return ans;
       }
       if(sum){
           ans+= temp*sum;
       }
       return ans;
        // Your code goes here
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
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends