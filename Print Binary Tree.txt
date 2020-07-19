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
    vector<vector<string>> printTree(TreeNode* root) {
        int d = depth(root), w = width(root);
        vector<vector<string>> res(d, vector<string>(w,""));
        printTree(root, res, 0, w/2,w/2);
        return res;
    }
    int depth(TreeNode* root){
        if(!root) return 0;
        return max(depth(root->left), depth(root->right))+1;
    }
    int width(TreeNode* root){
        if(!root) return 0;
        return max(width(root->left), width(root->right))*2+1;
    }
    void printTree(TreeNode* root, vector<vector<string>>& res, int d, int pos, int w){
        if(!root) return;
        res[d][pos].append(to_string(root->val));
        printTree(root->left, res, d+1, pos-w/2-1, w/2);
        printTree(root->right, res, d+1, pos+w/2+1, w/2);
    }
};