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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode *root=p.first;
            int x=p.second.first;
            int y=p.second.second;
            
            mp[x][y].insert(root->val);
            if(root->left!=NULL){
                q.push({root->left,{x-1,y+1}});
            }
            if(root->right!=NULL){
                q.push({root->right,{x+1,y+1}});
            }
        }
        vector<vector<int>>v;
        for(auto p: mp){
            vector<int>col;
            for(auto q: p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            v.push_back(col);
        }
        return v;
    }
};