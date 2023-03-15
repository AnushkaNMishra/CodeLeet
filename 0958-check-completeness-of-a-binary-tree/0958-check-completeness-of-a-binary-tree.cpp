/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, 
//and all nodes in the last level are as far left as possible. 
//It can have between 1 and 2h nodes at the last level h.


class Solution {
public:
   bool isCompleteTree(TreeNode* root) {
        bool pre = true;
        queue<TreeNode*> nq;
        nq.push(root);
        
        while(!nq.empty()){
            TreeNode* node = nq.front();
            nq.pop();
            
            if(node == NULL){
                pre = false;
            }
            else{
                if(pre == false)
                    return false;
                
                nq.push(node->left);
                nq.push(node->right);
            }
            
        }
        
        return true;
    }
};