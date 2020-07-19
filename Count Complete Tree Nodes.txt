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
    int countNodes(TreeNode* root) {
        return helper(root, treeDepth(root));
    }
    int helper(TreeNode* root, int depth){
        if (!root) return 0;
        int ld = treeDepth(root->left);
        int rd = treeDepth(root->right);
        if (ld == rd) return pow(2,ld)+helper(root->right, rd);
        else return pow(2,rd)+helper(root->left, ld);
    }
    int treeDepth(TreeNode* root){
        TreeNode* tmp = root;
        int count = 0;
        while(tmp){
            count++;
            tmp = tmp->left;
        }
        return count;
    }
};