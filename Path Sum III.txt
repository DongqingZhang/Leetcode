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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return findPath(root, sum)+pathSum(root->left, sum)+pathSum(root->right, sum);
    }
    int findPath(TreeNode* root, int sum){
        if(!root) return 0;
        int res = 0;
        if(root->val == sum) res++;
        res+=findPath(root->left, sum - root->val);
        res+=findPath(root->right, sum - root->val);
        return res;
    }
};