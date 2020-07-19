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
    void flatten(TreeNode* root) {
        if (!root) return;
        reshape(root);
    }
    TreeNode* reshape(TreeNode* root){
        TreeNode* tmp = nullptr;
        if (root->left) tmp = reshape(root->left);
        else tmp = root;
        if (tmp!=root){
            tmp->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        if (root->right){
            return reshape(root->right);
        }
        else return tmp;
    }
};