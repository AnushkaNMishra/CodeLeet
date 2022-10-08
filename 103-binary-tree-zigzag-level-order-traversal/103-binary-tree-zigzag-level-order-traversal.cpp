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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)return res;
        queue<TreeNode*>q;
        q.push(root);
        bool ltor=true;
        while(!q.empty()){
            int size=q.size();
            vector<int>v(size);
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();
                int index=(ltor)?i:(size-1-i); //checking the flag 
                
                v[index]=node->val; // inserted in oue vector
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            ltor=!ltor; //switching the flag
            res.push_back(v);
        }
        return res;
    }
};