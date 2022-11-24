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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = NULL;
        ListNode* prev = dummy;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                dummy->next = list1;
                list1 = list1->next;
                dummy = dummy->next;
            }
            else{
                dummy->next = list2;
                list2 = list2->next;
                dummy = dummy->next;
            }
        }

        while(list1 != NULL){
            dummy->next = list1;
            dummy = dummy->next;
            list1 = list1->next;
        }

        while(list2 != NULL){
            dummy->next = list2;
            dummy = dummy->next;
            list2 = list2->next;
        }

        return prev->next;
    }
};