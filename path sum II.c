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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        if (!root)
            return res;
        helper(res, cur, root, root->val, sum);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& cur, TreeNode* root, int curSum, int target){
        cur.push_back(root->val);
        if (!root->left && !root->right && curSum == target){
            res.push_back(cur);
        }
        if (root->right) helper(res, cur, root->right, curSum+root->right->val, target);
        if (root->left) helper(res, cur, root->left, curSum+root->left->val, target);
        cur.pop_back();
    }
};