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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        rightView(root,res,1);
        return res;
    }
    void rightView(TreeNode* root, vector<int>& res, int level){
        if(level>res.size()) res.push_back(root->val);
        if(root->right) rightView(root->right, res, level+1);
        if(root->left) rightView(root->left, res, level+1);
    }
};