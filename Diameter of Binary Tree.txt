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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        postorder(root, res);
        return res;
    }
    int postorder(TreeNode* root, int& res){
        if(!root) return 0;
        int l = postorder(root->left, res);
        int r = postorder(root->right, res);
        res = max(res, l+r);
        return max(l, r)+1;
    }
};