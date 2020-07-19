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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        helper(root, res, "");
        return res;
    }
    void helper(TreeNode* root, vector<string>& res, string tmp){
        if (!root) return;
        if (!root->left&&!root->right){
            res.push_back(tmp+to_string(root->val));
            tmp.clear();
            return;
        }
        helper(root->left, res, tmp+to_string(root->val)+"->");
        helper(root->right, res, tmp+to_string(root->val)+"->");
    }
};