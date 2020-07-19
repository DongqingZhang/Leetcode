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
    int kthSmallest(TreeNode* root, int k) {
        int *val;
        int count = 0;
        helper(root, &count, k, val);
        return *val;
    }
    void helper(TreeNode* root, int* count, int k, int* val){
        if (root->left != nullptr)
            helper(root->left, count, k,val);
        if (*count == k) return;
        *val = root->val;
        (*count)++;
        if (root->right != nullptr)
            helper(root->right, count, k,val);
    }
};