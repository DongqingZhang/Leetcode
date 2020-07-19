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
    int closestValue(TreeNode* root, double target) {
        double diff = abs(root->val-target);
        double close = root->val;
        while (root){
            if (abs(root->val-target)<diff) {diff = abs(root->val-target); close = root->val;}
            root = root->val>target?root->left:root->right;
        }
        return close;
    }
};