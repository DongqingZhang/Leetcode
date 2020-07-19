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
    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }
    
    int helper(TreeNode* root){
        if (!root)
            return 0;
        int left, right;
        left = helper(root->left);
        right = helper(root->right);
        if (left == -1 || right == -1)
            return -1;
        else if (abs(left - right)>1)
            return -1;
        else return max(left, right)+1;
    }
};