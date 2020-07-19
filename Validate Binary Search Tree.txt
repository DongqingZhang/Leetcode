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
    bool isValidBST(TreeNode* root) {
        vector<int> T;
        helper(root,T);
        if (!T.size())
            return true;
        if (T.size()==1)
            return true;
        for (int i=1;i<T.size();i++)
            if (T[i]<=T[i-1])
                return false;
        return true;
    }
private:
    void helper(TreeNode* root, vector<int>& T){
        if (!root) return;
        helper(root->left,T);
        T.push_back(root->val);
        helper(root->right,T);
    }
};