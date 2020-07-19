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
    int getMinimumDifference(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return INT_MAX;
        int res = min(getMinimumDifference(root->left),getMinimumDifference(root->right));
        if(root->left) res = min(res,root->val - getMax(root->left));
        if(root->right) res = min(res,getMin(root->right) - root->val);
        return res;
    }
    int getMin(TreeNode* root){
        if(!root->left) return root->val;
        return getMin(root->left);
    }
    int getMax(TreeNode* root){
        if(!root->right) return root->val;
        return getMax(root->right);
    }
};