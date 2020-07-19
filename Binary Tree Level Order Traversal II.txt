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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        helper(root, res, 0);
        reverse(res.begin(),res.end());
        return res;
    }
    void helper(TreeNode* root, vector<vector<int>>& res, int d){
        if (!root) return;
        if (res.size()<=d) res.push_back({});
        res[d].push_back(root->val);
        helper(root->left, res, d+1);
        helper(root->right, res, d+1);
    }
};