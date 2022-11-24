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
//class Solution {
//public:
  //  bool findTarget(TreeNode* root, int k) {
        
    //}
//};
class Solution {
public:
    bool targetsum(TreeNode* root,int k,set<int> &st)
    {
        if(root==NULL) return false;
        if(st.find(k-root->val)!=st.end())return true;
        st.insert(root->val);
        return targetsum(root->left,k,st)||targetsum(root->right,k,st);
    }
    bool findTarget(TreeNode* root, int k) {
    set<int> st;
        return targetsum(root,k,st);
    }
};