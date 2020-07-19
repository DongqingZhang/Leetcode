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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        pair<TreeNode*, TreeNode*> res = helper(root);
        return res.first;
    }
    pair<TreeNode*, TreeNode*> helper(TreeNode *root){
        if (!root||!root->left) return {root, root};
        else{
            pair<TreeNode*, TreeNode*> res = helper(root->left);
            res.second->right = root;
            res.second->left = root->right;
            root->right = nullptr;
            root->left = nullptr;
            res.second = root;
            return res;
        }
    }
};