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
    int count = 0;
    int countUnivalSubtrees(TreeNode* root) {
        helper(root);
        return count;
    }
    bool helper(TreeNode* root){
        if(!root) return true;
        if(!root->left&&!root->right){count++;return true;}
        bool i1=helper(root->left);
        bool i2=helper(root->right);
        if(i1&&i2){
            if (root->left&&root->left->val!=root->val) return false;
            if (root->right&&root->right->val!=root->val) return false;
            count++;
            return true;
        }
        return false;
    }
};