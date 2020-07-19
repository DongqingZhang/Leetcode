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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if(!root) return {nullptr, nullptr};
        if(root->val > V){
            if(maxi(root->left) <= V){
                TreeNode* l = root->left;
                root->left = nullptr;
                return {l, root};
            }
            vector<TreeNode*> v = splitBST(root->left, V);
            root->left = v[1];
            return {v[0], root};
        }
        if(root->val <= V){
            if(mini(root->right) > V){
                TreeNode* r = root->right;
                root->right = nullptr;
                return {root, r};
            }
            vector<TreeNode*> v = splitBST(root->right, V);
            root->right = v[0];
            return {root, v[1]};
        }
    }
    int maxi(TreeNode* node){
        if(!node) return INT_MIN;
        int res = INT_MIN;
        while(node = node->right) res = max(res,node->val);
        return res;
    }
    int mini(TreeNode* node){
        if(!node) return INT_MAX;
        int res = INT_MAX;
        while(node = node->left) res = min(res,node->val);
        return res;
    }
};