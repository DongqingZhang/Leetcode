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
    int maxPathSum(TreeNode* root) {
        int res;
        res = INT_MIN;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, int& res){
        if (!root)
            return 0;
        int tmp1 = helper(root->left, res);
        int tmp2 = helper(root->right, res);
        int cur = root->val + max(tmp1,0) + max(tmp2,0);
        if (cur > res)
            res = cur;
        return root->val + max(max(tmp1,tmp2),0);
    }
};