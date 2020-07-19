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
    int maxlen = 0;
    int longestConsecutive(TreeNode* root) {
        helper(root);
        return maxlen;
    }
    pair<int,int> helper(TreeNode* root){
        if(!root) return {0,0};
        int inc = 1, dec = 1;
        pair<int,int> left = helper(root->left);
        pair<int,int> right = helper(root->right);
        if(root->left){
            if(root->left->val == root->val+1) inc+=left.first;
            if(root->left->val == root->val-1) dec+=left.second;
        }
        if(root->right){
            if(root->right->val == root->val+1) inc=max(inc,right.first+1);
            if(root->right->val == root->val-1) dec=max(dec,right.second+1);
        }
        maxlen = max(maxlen, inc+dec-1);
        return {inc, dec};
    }
};