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
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        postorder(root, res);
        return res;
    }
    int postorder(TreeNode* root, int& result){
        if(!root) return 0;
        int l = postorder(root->left, result);
        int r = postorder(root->right, result);
        result += abs(l - r);
        return l+r+root->val;
    }
};