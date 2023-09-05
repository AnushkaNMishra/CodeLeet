/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node *copy(Node* from,unordered_map<Node*,Node*>&m){
        if(m[from])return m[from];
        int v = from->val;
        Node* to = new Node(v);
        m[from]=to;
        if(from->next)to->next = copy(from->next,m);
        if(from->random)to->random = copy(from->random,m);
        return to;
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        unordered_map<Node*,Node*>m;
        return copy(head,m);
    }
};