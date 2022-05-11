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
    int isBalance(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int lh = isBalance(root->left);
        int rh = isBalance(root->right);
        if(lh==-1 || rh==-1){
            return -1;
        }
        
        return abs(lh-rh)<=1 ? max(lh,rh)+1 : -1;
    }
    bool isBalanced(TreeNode* root) {
        
        if(isBalance(root)==-1)
            return false;
        return true;
    }
};