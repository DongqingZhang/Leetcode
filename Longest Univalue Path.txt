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
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int res1 = helper(root->left, root->val)+helper(root->right, root->val)+2;
        int res2 = max(longestUnivaluePath(root->left),longestUnivaluePath(root->right));
        return max(res1, res2);
    }
    int helper(TreeNode* root, int val){
        if(!root || root->val != val) return -1;
        if(root->val == val) return max(helper(root->left, val),helper(root->right, val))+1;
    }
};