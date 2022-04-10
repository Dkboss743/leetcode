// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
       int search(int start,int end,int arr[]){
           int max = INT_MIN;
           for(int j = start  ; j<end ; j++){
               if(arr[j]>max)
               max= arr[j];
           }
           if(max == INT_MIN){
               return INT_MAX;
           }
           return max;
       }
    long long trappingWater(int arr[], int n){
        // code here
        long long int water = 0;
        vector<int> max_ele(n);
        vector<int> min_ele(n);
        max_ele[0] = arr[0];
        int maxi = INT_MIN;
        for(int i=1 ; i<n ; i++){
            max_ele[i] = max(max_ele[i-1] , arr[i]);
        }
        min_ele[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            min_ele[i] = max(arr[i], min_ele[i+1]);
        }

        for(int i=1 ; i<n-1 ; i++){
            int a = max_ele[i-1];
            int b = min_ele[i+1];
            // cout << a << " % " << b << " % " << min(a,b)-arr[i]<< " i " << i <<   endl;
            int k=min(a,b)-arr[i];
            if(k>0)
            water+=k;
            
        }
        return water;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends