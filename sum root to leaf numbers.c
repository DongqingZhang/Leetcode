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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
    void dfs(TreeNode* root, int curSum, int& sum){
        int newVal = curSum*10 + root->val;
        if (!root->left&&!root->right){
            sum += newVal;
            return;
        }
        if (root->left)
            dfs(root->left, newVal, sum);
        if (root->right)
            dfs(root->right, newVal, sum);
    }
};