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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0) return res;
        return helper(1,n);
    }
    vector<TreeNode*> helper(int l, int r){
        vector<TreeNode*> res;
        if (l > r) return {nullptr};
        for (int i = l;i <= r;i++){
            vector<TreeNode*> res1 = helper(l, i-1);
            vector<TreeNode*> res2 = helper(i+1, r);
            for (int j = 0;j<res1.size();j++)
                for (int k = 0;k<res2.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = res1[j];
                    root->right = res2[k];
                    res.push_back(root);
                }
        }
        return res;
    }
};