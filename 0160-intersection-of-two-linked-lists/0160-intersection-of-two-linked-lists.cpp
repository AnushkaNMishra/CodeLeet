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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*ListNode *temp=NULL;
        //while(headA!=NULL){
        //    temp=headB;
            while(temp!=NULL){
                if(temp==headA){
                    return headA;
                }
                temp=temp->next;
            }
            headA=headA->next;
        }
        return NULL;
        */
        ListNode *p=headA;
        ListNode *q=headB;
        
        while(p!=q){
            p=p->next;
            q=q->next;
            if(p==q)return p;
            if(p==NULL)p=headB;
            if(q==NULL)q=headA;
        }
        return p;
    }
};