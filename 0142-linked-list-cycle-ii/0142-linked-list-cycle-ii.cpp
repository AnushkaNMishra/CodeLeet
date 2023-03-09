/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        if(!(fast && fast->next)){
            return NULL;
        }
        while(head!=slow){
            head=head->next;
            slow=slow->next;
            }
        return head;
        }
};


// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_map<ListNode*,int>mp;
//         ListNode* curr=head;
//         while(curr!=NULL){
//             if(mp[curr]>1){
//                 return curr;
//             }
//             mp[curr]++;
//             curr=curr->next;
//         }
//         return NULL;
//     }
// };