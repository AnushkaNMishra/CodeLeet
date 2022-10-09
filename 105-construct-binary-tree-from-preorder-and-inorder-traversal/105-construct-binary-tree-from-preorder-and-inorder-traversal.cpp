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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>map;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        TreeNode* root=helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,map);
        return root;
    }
    
    TreeNode* helper(vector<int>& preorder, int pstart, int pend, vector<int>& inorder, int istart,int iend, map<int,int>&map){
        if(pstart>pend || istart>iend){
            return 0;
        }
        TreeNode *root =new TreeNode(preorder[pstart]);
        int iroot=map[root->val];
        int nums=iroot-istart;
        root->left=helper(preorder, pstart+1,pstart+nums,inorder,istart,iroot-1,map);
        root->right=helper(preorder, pstart+nums+1,pend,inorder,iroot+1,iend,map);
        return root;

    }
    
};