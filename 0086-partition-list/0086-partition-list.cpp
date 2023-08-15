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
    ListNode* partition(ListNode* head, int x) {
    if(head==NULL ||head->next==NULL)return head;
      ListNode*temp1=new ListNode(-1);
      ListNode*temp2=new ListNode(-1);
      ListNode*maxi=temp2,*mini=temp1;
      ListNode*t=head;
      
      while(t!=NULL){
        if(t->val<x){
          mini->next=t;
          mini=mini->next;
        }
        if(t->val>=x){
          maxi->next=t;
          maxi=maxi->next;
        }
        t=t->next;
      }
      maxi->next=NULL;
      mini->next=temp2->next;
      return temp1->next;
      
    }
};