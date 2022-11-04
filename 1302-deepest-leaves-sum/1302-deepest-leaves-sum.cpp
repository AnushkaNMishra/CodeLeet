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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>qu;
        int ans=0;
        qu.push(root);
        while(!qu.empty()){
            int level=0;
            int s=qu.size();
            for(int i=0;i<s;i++){
                TreeNode* node=qu.front();
                qu.pop();
                level=level+node->val;
                if(node->right){
                    qu.push(node->right);
                }
                if(node->left){
                    qu.push(node->left);
                }
            }
            ans=level;
        }
        return ans;
    }
};