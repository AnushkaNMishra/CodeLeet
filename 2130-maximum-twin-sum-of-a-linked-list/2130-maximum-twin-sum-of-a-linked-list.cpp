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
    int pairSum(ListNode* head) {
        stack<int>st;
        ListNode* curr=head;
        int l=0;
        while(curr!=NULL){
            curr=curr->next;
            l++;
        }
        
        int i=0;
        curr=head;
        while(i<l/2){
            st.push(curr->val);
            curr=curr->next;
            i++;
        }   
         
        int maxi=0;
        while(i<l){
            maxi=max(maxi,curr->val+st.top());
            st.pop();
            i++;
            curr=curr->next;
        }
        return maxi;
    }
};