/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return helper(root->left, true)+helper(root->right, false);
    }
    int helper(TreeNode* root, bool flag){
        if(!root) return 0;
        if(!root->left && !root->right){
            if (flag) return root->val;
            else return 0;
        }
        return helper(root->left, true)+helper(root->right, false);
    }
};