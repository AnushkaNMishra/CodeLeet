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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTreesHelper(1, n);
    }

    vector<TreeNode*> generateTreesHelper(int start, int end) {
        vector<TreeNode*> result;

        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftSubtrees = generateTreesHelper(start, i - 1);
            vector<TreeNode*> rightSubtrees = generateTreesHelper(i + 1, end);

            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }

        return result;
    }
};

//1. we are givenm n nodes
// we need to consider each node from 1 to n as a root
// and  reciursively geenrate the possible left and right subtrees

// 2. start = 1 end=n
// for each i from start to end, we can consider it as the root of the currect BST

//3. we can rec generate the possible left trres => values start to i-1
   // consider i=3 THAT IS THE ROOT
   // this is beacuse consider i=3 then at left we can have 2 and 1 , hence start=1 to i-1=3-1=2;
//4.  generate all possible=> right subtrees with values from =>'i+1' to end 
   // this is because we can consider i=3 where n=5 , so at right side we will have 4, 5


//5. now for each left subtree and right subtree pair, we can create => new root node
// that has value 'i' ==> left : set its left ; ==> right : set the right 

// 6. add the new root to the resultant vector
// 7. Repeat the steps 

// for every root value i; we are going through every possible vlaue for making left and right subtree 
// i^n  roughly u think so 
// i=> start to end