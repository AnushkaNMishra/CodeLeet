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
// class Solution {
// public:
//     vector<int> findMode(TreeNode* root) {
        
//     }
// };
class Solution 
{
public:
    void inorder(TreeNode *root,int &curr,int &currcount,int &maxcount,vector<int> &ans)
    {
        if(root)
        {
            inorder(root->left,curr,currcount,maxcount,ans);

            if(root->val==curr)
            {
                currcount++;
            }

            else
            {
                curr=root->val;
                currcount=1;
            }

            if(currcount==maxcount)
            {
                ans.push_back(curr);
            }

            else if(currcount>maxcount)
            {
                maxcount=currcount;

                ans.clear();
                ans.push_back(curr);
            }

            inorder(root->right,curr,currcount,maxcount,ans);
        }
    }

    vector<int> findMode(TreeNode* root) 
    {
        int curr,currcount,maxcount;
        curr=INT_MAX;
        currcount=0;
        maxcount=0;

        vector<int> ans;

        inorder(root,curr,currcount,maxcount,ans);

        return ans;       
    }
};