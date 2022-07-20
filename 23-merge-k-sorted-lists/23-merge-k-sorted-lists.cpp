/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode *>,vector<pair<int,ListNode *>> , greater<pair<int,ListNode*>>>data;
        int n = lists.size();
        for(int i=0; i<n ; i++){
            if(lists[i]){
                data.push({lists[i]->val , lists[i]});
            }
        }
        ListNode *head=nullptr;
        ListNode *ans;
        ListNode *temp;
        while(!data.empty()){
            temp = data.top().second;
            int val = data.top().first;
            if(!head){
                head = temp;
                ans = head;
            }
            else{
                head->next = temp;
                head = head->next;
            }
            if(temp->next){
                data.pop();
                temp = temp->next;
                data.push({temp->val , temp});
            }
            else{
                data.pop();
            }
        }
        return ans;
    }
};