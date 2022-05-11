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
    int sumOfLeftLeaves(TreeNode* root, int val = 0) {
        
        if(root == NULL)
            return 0;
        
        if(root->left == NULL && root->right == NULL && val)
            return root->val;
        
        return sumOfLeftLeaves(root->left,1)+sumOfLeftLeaves(root->right,0);
    }
};