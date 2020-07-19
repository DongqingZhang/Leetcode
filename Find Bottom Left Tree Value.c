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
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tmp;
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            if(tmp->right) q.push(tmp->right);
            if(tmp->left) q.push(tmp->left);
        }
        return tmp->val;
    }
};