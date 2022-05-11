// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 // } Driver Code Ends
//User function Template for C

//Function to arrange all letters of a string in lexicographical 
//order using Counting Sort.
char* quicksort(char number[],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
         i++;
         while(number[j]>number[pivot])
         j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
   return number;
}
char* countSort(char arr[]){
    
    //Your code here
    int n = strlen(arr);
    char* ans = quicksort(arr,0,n-1);
    
    return ans;
    
}

// { Driver Code Starts.

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		char str[n+1];
		scanf("%s", str);
		printf("%s\n", countSort(str));

	}
	return 0;

}  // } Driver Code Ends