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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty()){
            int maxv = INT_MIN;
            int n = q.size();
            for(int i = 0;i<n;i++){
                TreeNode* tmp = q.front();
                if(tmp->val > maxv) maxv = tmp->val;
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            res.push_back(maxv);
        }
        return res;
    }
};