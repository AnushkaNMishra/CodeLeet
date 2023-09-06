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
    
    int listcount(ListNode* head) //function to count number of nodes
    {
        int count = 0;
        while(head)
        {
            count++;
            head = head->next;
        }
        return count;
    }
    
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = listcount(head);
        int x = k;      
        int n = count/k;            //size of every list after splitting
        k = count%k;                //number of lists with an extra node
        vector<ListNode*> ans;
        
        ListNode* point = head;
        ListNode* hd = NULL;
        while(point)                //traversing the original list
        {
            ans.push_back(point);   //push heads of new lists
            count = 0;
            if(k>0)
                count = 1;
            
            for(int i = 0; i < n+count ; i++)
            {
                hd = point;
                point = point->next;
            }
            hd->next = NULL;
            k--;
        }
        while(ans.size() != x)     //if the number of nodes 
        {                          //are less than k then we 
            ans.push_back(NULL);   //need to push NULL into vector
        }
        return ans;
    }
};