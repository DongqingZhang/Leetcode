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
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int maxv = 0;
        helper(root, &maxv, 0, root->val-1);
        return maxv;
    }
    void helper(TreeNode* root, int* maxv, int curv, int val){
        if (!root) return;
        if (root->val-val == 1) curv++;
        else curv = 1;
        *maxv = max(*maxv,curv);
        helper(root->left, maxv, curv, root->val);
        helper(root->right, maxv, curv, root->val);
    }
};