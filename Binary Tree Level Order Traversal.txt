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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int d = depth(root);
        vector<vector<int>> res(d, vector<int>());
        helper(root, res, 0);
        return res;
    }
    int depth(TreeNode* root){
        if (!root) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    void helper(TreeNode* root, vector<vector<int>>& res, int d){
        if (!root) return;
        res[d].push_back(root->val);
        helper(root->left,res,d+1);
        helper(root->right,res,d+1);
    }
};