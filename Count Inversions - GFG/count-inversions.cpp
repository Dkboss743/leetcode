// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
  
    long long int merge(long long *arr , int s , int e){
        long long int i = s;
        long long int m = (s+e)/2;
        long long int j = m+1;
        long long int count = 0;
        vector<long long int>temp;
        while(i<=m && j<=e){
            if(arr[i] <=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                count += m-i+1;
                j++;
            }
        }
        while(i<=m){
            temp.push_back(arr[i++]);
        }
        while(j<=e){
            temp.push_back(arr[j++]);
        }
        long long int k = 0;
        for(long long int idx = s; idx <=e ; idx++){
            arr[idx] = temp[k++];
        }
        return count;
    }
    long long int mergesort(long long arr[] , long long low , long long high){
        if(low >= high){
            return 0;
        }
        long long int mid = (low + high)/2;
        long long int x = mergesort(arr , low , mid);
        long long int y = mergesort(arr, mid+1, high);
        return merge(arr , low , high) + x + y;
    }
    long long int inversionCount(long long arr[], long long N)
    {
       return mergesort(arr, 0 ,N-1);
     
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends