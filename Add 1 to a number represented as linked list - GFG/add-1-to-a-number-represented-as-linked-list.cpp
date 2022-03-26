// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node *reverse(Node *head){
        Node *curr=head;
        Node *fut = NULL;
        Node *prev = NULL;
        while(curr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        head = reverse(head);
        Node *curr = head;
        Node *prev = head;
        int carry =0;
        int val = 1;
        while(curr){
            prev = curr;
            val = val + curr->data;
            carry = val%10;
            val = val/10;
            curr->data =  carry;
            curr = curr->next;
        }
        if(val){
            prev->next = new Node(val);
        }
        head = reverse(head);
        return head;
        
        // Your Code here
        // return head of list after adding one
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends