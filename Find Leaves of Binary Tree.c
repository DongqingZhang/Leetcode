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
    vector<vector<int>> findLeaves(TreeNode* root) {
        int d = depth(root);
        vector<vector<int>> res(d,vector<int>());
        if (d == 0) return res;
        helper(root, res);
        return res;
    }
    int depth(TreeNode* root){
        if (!root) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    int helper(TreeNode* root, vector<vector<int>>& res){
        if (!root) return -1;
        if (!root->left&&!root->right){
            res[0].push_back(root->val);
            return 0;
        }
        int layer = max(helper(root->left,res),helper(root->right,res))+1;
        res[layer].push_back(root->val);
        return layer;
    }
};