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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return treeSym(root->left, root->right);
    }
private:
    bool treeSym(TreeNode* node1, TreeNode* node2){
        if (!node1&&!node2) return true;
        if (node1&&node2){
            return treeSym(node1->left, node2->right)&&treeSym(node1->right, node2->left)&&node1->val==node2->val;
        }
        return false;
    }
};
